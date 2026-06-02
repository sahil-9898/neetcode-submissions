class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int seen[128] = {};
        int left = 0;
        int right = 0;

        int l = s.length();
        int res = 0;
        while (right < l) {
            if (seen[s[right]] == 1) {
                while (left < right && s[left] != s[right]) {
                    seen[s[left]] = 0;
                    left++;
                }
                left++;
            }
            res = max(res, right - left + 1);
            seen[s[right]] = 1;
            right++; 
        }

        return res;
    }
};
