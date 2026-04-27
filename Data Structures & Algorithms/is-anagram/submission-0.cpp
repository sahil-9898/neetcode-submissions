class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> charMap(0);
        for (auto c: s) {
            charMap[c]++;
        }
        for (auto c: t) {
            charMap[c]--;
            if (charMap[c] < 0) return false; 
        }
        return true;
    }
};
