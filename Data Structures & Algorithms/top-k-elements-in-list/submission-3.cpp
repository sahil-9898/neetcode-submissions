class Solution {
public:
    static bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
        return p1.second > p2.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int n: nums) {
            mp[n]++;
        }
        vector<pair<int, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), cmp);
        vector<int> res;
        for (int i=0;i<k;i++) {
            res.push_back(v[i].first);
        }
        return res;
    }
};
