#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class TrieNode {
public:
    TrieNode *children[26];
    bool isEndOfWord;
    TrieNode() {
        isEndOfWord = false;
        fill(begin(children), end(children), nullptr);
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() { root = new TrieNode(); }
    
    void insert(const string& word) {
        TrieNode *node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) 
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isEndOfWord = true;
    }
};

void searchWords(vector<vector<char>>& board, int i, int j, TrieNode *node, string& currentWord, unordered_set<string>& result) {
    if (node->isEndOfWord) {
        result.insert(currentWord);
    }
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
        return;

    char temp = board[i][j];
    if (temp == '#' || !node->children[temp - 'a']) return;

    board[i][j] = '#'; // Mark as visited
    currentWord.push_back(temp);

    searchWords(board, i + 1, j, node->children[temp - 'a'], currentWord, result);
    searchWords(board, i - 1, j, node->children[temp - 'a'], currentWord, result);
    searchWords(board, i, j + 1, node->children[temp - 'a'], currentWord, result);
    searchWords(board, i, j - 1, node->children[temp - 'a'], currentWord, result);

    board[i][j] = temp; // Restore original character
    currentWord.pop_back(); // Backtrack
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie trie;
    for (const string& word : words) {
        trie.insert(word);
    }
    
    unordered_set<string> result;
    string currentWord;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            searchWords(board, i, j, trie.root, currentWord, result);
        }
    }
    return vector<string>(result.begin(), result.end());
}

int main() {
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };
    vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<string> foundWords = findWords(board, words);
    
    for (const string& word : foundWords) {
        cout << word << endl;
    }
    return 0;
}
