#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void backtrack(const string& digits, int index, string& current, vector<string>& result, const unordered_map<char, string>& phone) {
    if (index == digits.size()) {
        result.push_back(current);
        return;
    }
    char digit = digits[index];
    const string& letters = phone.at(digit);
    
    for (char letter : letters) {
        current.push_back(letter);
        backtrack(digits, index + 1, current, result, phone);
        current.pop_back();
    }
}

vector<string> letterCombinations(const string& digits) {
    unordered_map<char, string> phone = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    vector<string> result;
    if (digits.empty()) return result;
    string current;
    backtrack(digits, 0, current, result, phone);
    return result;
}

int main() {
    string digits = "23";
    vector<string> combinations = letterCombinations(digits);
    
    for (const string& combination : combinations) {
        cout << combination << endl;
    }
    return 0;
}
