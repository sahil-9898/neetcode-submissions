class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        vector<vector<int> > freq(nums.size() + 1);
        for (auto n: nums) {
            countMap[n]++;
        }
        for (auto [val, count]: countMap) {
            freq[count].push_back(val);
        }

        vector<int> res;
        for (size_t i = freq.size() - 1; i > 0; --i) {
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
