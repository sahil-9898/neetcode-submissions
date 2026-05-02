class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        bool found = false;
        for (string s: strs) {
            found = false;
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            for (vector<string> &v: res) {
                string firstStr = v[0];
                sort(firstStr.begin(), firstStr.end());
                if (firstStr == sortedS) {
                    v.push_back(s);
                    found = true;
                    break;
                }
            }
            if (found == false) {
                res.push_back({s});
            }
        }
        return res;
    }
};
