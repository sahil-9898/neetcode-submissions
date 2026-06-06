class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> countt;
        for (char c: t) {
            countt[c]++;
        }

        int need = countt.size();
        int have = 0;

        int res = INT_MAX;
        pair<int, int> resPair = {-1, -1};

        for (int i=0; i<s.length(); i++) {
            unordered_map<char, int> counts;
            have = 0;
            for (int j=i; j<s.length(); j++) {
                counts[s[j]]++;
                if (countt[s[j]] == counts[s[j]]) {
                    have++;
                }
                if (have == need) {
                    int len = j-i+1;
                    if (len < res) {
                        res = len;
                        resPair = {i ,j};
                    }
                }
            }
        }

        if (res == INT_MAX) return "";
        return s.substr(resPair.first, res);
    }
};
