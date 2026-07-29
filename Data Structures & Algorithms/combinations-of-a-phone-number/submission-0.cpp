class Solution {
public:
    vector<string> res;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        backtrack(digits, 0, "");
        return res;
    }

    void backtrack(string digits, int index, string curr) {
        if (index >= digits.length()) {
            res.push_back(curr);
            return;
        }

        string s = digitToChar[digits[index] - '0'];
        for (char c: s) {
            backtrack(digits, index + 1, curr + c);
        }
    }

};
