class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> countt;

        for (char c: t) {
            countt[c]++;
        }

        int res = INT_MAX;
        int startIndex = -1;

        int need = countt.size();
        int have = 0;
        int l = 0;
        unordered_map<char, int> window;

        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;

            if (countt.contains(c) && countt[c] == window[c]) {
                have++;
            }

            while (have == need) {
                if (r - l + 1 < res) {
                    res = r - l + 1;
                    startIndex = l;
                }
                window[s[l]]--;
                if (countt.contains(s[l]) && window[s[l]] < countt[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        if(res == INT_MAX) return "";
        return s.substr(startIndex, res);
    }
};
