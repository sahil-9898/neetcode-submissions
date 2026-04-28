class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        int a[128] = {};
        for (char c: s) {
            a[c]++;
        }
        for (char c: t) {
            a[c]--;
            if (a[c] < 0) {
                return false;
            }
        }
        return true;
    }
};
