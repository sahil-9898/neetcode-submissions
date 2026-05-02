class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (const string& s : strs) {
            array<int, 26> freq = {};
            for (char c : s) freq[c - 'a']++;

            string key(freq.begin(), freq.end());
            mp[key].push_back(s);
        }

        vector<vector<string>> res;
        res.reserve(mp.size());
        for (auto& [key, group] : mp)
            res.push_back(move(group));

        return res;
    }
};



