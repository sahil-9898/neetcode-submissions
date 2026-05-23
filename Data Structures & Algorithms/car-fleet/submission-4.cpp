class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pairs;
        int n = position.size();
        for (int i=0; i<n; i++) {
            pairs.push_back({position[i], speed[i]});
        }

        sort(pairs.rbegin(), pairs.rend());

        double curr = -1;
        int res = 0;
        for (auto& p: pairs) {
            double time = (double)(target - p.first) / p.second;
            if (time > curr) {
                curr = time;
                res++;
            }
        }
        return res;
    }
};
