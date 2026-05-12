class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            int start = nums[i];
            int len = 1;
            bool found = false;
            int nextElement = start + 1;
            do {
                found = false;
                for (int j=0; j<n; j++) {
                    if (nums[j] == nextElement) {
                        found = true;
                        len++;
                        nextElement++;
                        break;
                    }
                }
            } while (found == true);
            res = max(res, len);
        }
        return res;
    }
};
