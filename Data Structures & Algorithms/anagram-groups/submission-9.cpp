class Solution {
public:
    string getAnagramRepresentation(string &s) {
        vector<int> l(26, 0);
        for (char c: s) {
            l[c - 'a']++;
        }
        string res = to_string(l[0]);
        for (int i=1;i<26;i++) {
            res+=",";
            res+=to_string(l[i]);
        }
        return res;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> mp;
        for (string s: strs) {
            string aRep = getAnagramRepresentation(s);
            if (mp.find(aRep) != mp.end()) {
                res[mp[aRep]].push_back(s);
            }
            else {
                res.push_back({s});
                mp[aRep] = res.size()-1;
            }
        }
        return res;
    }

};
