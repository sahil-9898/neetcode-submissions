class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int left = 0;
        int res = 0;

        for (int r=0; r<s.length(); r++) {
            if (mp.find(s[r]) != mp.end()) {
                left = max(mp[s[r]] + 1, left);
            }
            mp[s[r]] = r;
            res = max(res, r-left+1);
        }
        return res;
    }
};
