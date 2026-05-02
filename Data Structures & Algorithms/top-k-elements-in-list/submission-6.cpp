class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int n:nums) {
            mp[n]++;
        }
        vector<vector<int>> freq(nums.size()+1);
        for (pair<const int, int> &entry:mp) {
            freq[entry.second].push_back(entry.first);
        }

        vector<int> res;
        for (int i=freq.size()-1; i>=0; i--) {
            vector<int> arr = freq[i];
            for (int x: arr) {
                res.push_back(x);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};
