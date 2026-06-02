class Solution {
private:
    bool isUnique(string &s, int start, int end) {
        int seen[128] = {};
        for (int i=start; i<=end; i++) {
            if (seen[s[i]] == 1) return false;
            seen[s[i]] = 1;
        }
        return true;
    }
 
public:
    int lengthOfLongestSubstring(string s) {
        int l = s.length();
        int res = 0;
        for (int i=0; i<l; i++) {
            for (int j=i; j<l; j++) {
                if (isUnique(s, i, j)) {
                    res = max(res, j-i+1);
                }
            }
        }
        return res;
    }
};
