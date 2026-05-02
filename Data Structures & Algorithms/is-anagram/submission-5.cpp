class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        if (n1 != n2) {
            return false;
        }
        bool found;
        for (char c: s) {
            found = false;
            for (char d: t) {
                if (c == d) {
                    found = true;
                }
            }
            if (found == false) {
                return false;
            }
        }
        return true;
    }
};
