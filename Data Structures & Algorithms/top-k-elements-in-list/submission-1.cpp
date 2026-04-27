class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        vector<vector<int>> freq(nums.size() + 1);
        for (auto n: nums) {
            countMap[n]++;
        }
        for (auto entry: countMap) {
            freq[entry.second].push_back(entry.first);
        }

        vector<int> res;
        for (int i=freq.size()-1; i>=0; i--) {
            for (int n: freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};
