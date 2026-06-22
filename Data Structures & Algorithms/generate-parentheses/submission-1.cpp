class Solution {
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        string curr = "";
        backtrack(0, 0, n, curr);
        return res;
    }
private:
    void backtrack(int open, int close, int n, string curr) {
        if (open == n && close == n) {
            res.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');
            backtrack(open + 1, close, n, curr);
            curr.pop_back();
        }
        if (open > close) {
            curr.push_back(')');
            backtrack(open, close + 1, n, curr);
            curr.pop_back();
        }
    }
};
