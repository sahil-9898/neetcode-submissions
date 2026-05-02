class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> mp;
        for (string s: strs) {
            string s1 = s;
            sort(s1.begin(), s1.end());
            if (mp.find(s1) != mp.end()) {
                res[mp[s1]].push_back(s);
            }
            else {
                res.push_back({s});
                mp[s1] = res.size()-1;
            }
        }
        return res;
    }
};
