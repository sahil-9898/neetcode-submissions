class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int n = nums.size();
        for (int i=0; i<n; i++) {
            int curr = nums[i];
            if (s.find(curr-1) != s.end()) {
                continue;
            }
            int len = 0;
            while (s.find(curr) != s.end()) {
                curr++;
                len++;
            }
            res = max(res,len);
        }
        return res;
    }
};
