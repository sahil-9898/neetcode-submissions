class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charset;
        int left = 0;
        int res = 0;

        for (int r=0; r<s.length(); r++) {
            while (charset.find(s[r]) != charset.end()) {
                charset.erase(s[left]);
                left++;
            }
            charset.insert(s[r]);
            res = max(res, r-left+1);
        }
        return res;
    }
};
