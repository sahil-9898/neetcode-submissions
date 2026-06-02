class Solution {
private:
    bool isUnique(string &s) {
        int seen[128] = {};
        for (auto c: s) {
            if (seen[c] == 1) {
                return false;
            }
            seen[c] = 1;
        }
        return true;
    } 
public:
    int lengthOfLongestSubstring(string s) {
        int l = s.length();
        int res = 0;
        for (int i=0; i<l; i++) {
            for (int j=i; j<l; j++) {
                string substrc = s.substr(i, j-i+1);
                if (isUnique(substrc)) {
                    res = max(res, j-i+1);
                }
            }
        }
        return res;
    }
};
