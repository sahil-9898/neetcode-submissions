class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<pair<int, int>> stk; // pair<Temp, Index>

        for (int i=0; i<n; i++) {
            if (stk.empty() || temperatures[i] <= stk.top().first) {
                stk.push({temperatures[i],i});
            }
            else {
                while (!stk.empty() && stk.top().first < temperatures[i]) {
                    pair<int, int> top = stk.top();
                    res[top.second] = i-top.second;
                    stk.pop();
                }
                stk.push({temperatures[i], i});
            }
        }
        return res;
    }
};
