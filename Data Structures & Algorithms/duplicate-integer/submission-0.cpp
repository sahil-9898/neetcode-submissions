class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for (auto num: nums) {
            if (mp[num]) return true;
            mp[num] = true;
        }
        return false;
    }
};
