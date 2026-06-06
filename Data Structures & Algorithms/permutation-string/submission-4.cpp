class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        int left = 0;
        int right = s1.length() - 1;
        sort(s1.begin(), s1.end());
        while (left <= s2.length()-s1.length()) {
            string subStr = s2.substr(left, s1.length());
            right++;
            left++;
            sort(subStr.begin(), subStr.end());
            if (s1 == subStr) return true;
        }
        return false;
    }
};
