class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        if (n1 != n2) {
            return false;
        }
        int cnt1;
        int cnt2;
        for (char c: s) {
            for (char c1: s){
                if (c==c1){
                    cnt1++;
                }
            }
            for (char c2: t){
                if (c==c2){
                    cnt2++;
                }
            }
            if (cnt1!=cnt2) {
                return false;
            }
        }
        return true;
    }
};
