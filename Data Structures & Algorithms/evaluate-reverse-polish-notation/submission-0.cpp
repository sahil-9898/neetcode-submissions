class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string s: tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int x = stk.top(); stk.pop();
                int y = stk.top(); stk.pop();
                if (s == "+") stk.push(y + x);
                else if (s == "-") stk.push(y - x);
                else if (s == "*") stk.push(y * x);
                else if (s == "/") stk.push(y / x);
            } else {
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};
