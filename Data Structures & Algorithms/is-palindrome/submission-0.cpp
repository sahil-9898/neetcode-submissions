class Solution {
public:
    bool isPalindrome(string s) {
        int l = s.length();
        if (l < 2) return true;
        int left = 0, right = l-1;
        while (left < right) {
            while (!isalnum(s[left]) && left < right) {
                left++;
            }
            while (!isalnum(s[right]) && left < right) {
                right--;
            }
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
