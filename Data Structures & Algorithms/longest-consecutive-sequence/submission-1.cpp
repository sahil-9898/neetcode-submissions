class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            int curr = nums[i];
            int len = 0;
            while (s.find(curr) != s.end()) {
                len++;
                curr++;
            }
            res = max(res, len);
        }
        return res;
    }
};
