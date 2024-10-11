#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

void partitionHelper(vector<vector<string>>& result, vector<string>& current, string& s, int start) {
    if (start >= s.size()) {
        result.push_back(current);
        return;
    }
    for (int end = start; end < s.size(); end++) {
        if (isPalindrome(s, start, end)) {
            current.push_back(s.substr(start, end - start + 1));
            partitionHelper(result, current, s, start + 1);
            current.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> current;
    partitionHelper(result, current, s, 0);
    return result;
}

int main() {
    string s = "aab";
    vector<vector<string>> result = partition(s);
    for (const auto& partition : result) {
        for (const auto& str : partition) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
