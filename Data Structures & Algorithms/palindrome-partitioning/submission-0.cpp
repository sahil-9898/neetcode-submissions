class Solution {

private:
    void dfs(int i, string &s, vector<string> &part, vector<vector<string>> &res) {
        if (i>=s.length()) {
            res.push_back(part);
            return;
        }

        for (int x=i;x<s.length();x++) {
            if (isPalin(s, i, x)) {
                part.push_back(s.substr(i,x-i+1));
                dfs(x+1, s, part, res);
                part.pop_back();
            }
        }
    }

    bool isPalin(string &s, int i, int j) {
        while (i<j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;

        dfs(0, s, part, res);
        return res;
    }
};
