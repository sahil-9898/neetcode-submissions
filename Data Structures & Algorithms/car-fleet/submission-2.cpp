class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pairs;
        int n = position.size();
        
        for (int i=0; i<n; i++) {
            pairs.push_back({position[i], speed[i]});
        }
        
        sort(pairs.rbegin(), pairs.rend());

        stack<double> stk;
        for (auto& p: pairs) {
            double time = (double)(target - p.first) / p.second;
            if (stk.empty()) stk.push(time);
            else if (time > stk.top()) stk.push(time);
        }

        return stk.size();
    }
};
