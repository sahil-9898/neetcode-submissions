class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2);
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i=0; i<n; i++) {
            int x = target - nums[i];
            if (mp.find(x) != mp.end()) {
                res[0] = i;
                res[1] = mp.at(x);
                sort(res.begin(), res.end());
                return res;
            }
            mp[nums[i]] = i;
        }
        return res;
    }
};
