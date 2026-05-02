class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (string &s: strs) {
            res+=to_string(s.length())+"#"+s;
        }
        return res;
    }

    vector<string> decode(string s) {
        string countStr = "";
        vector<string> res;
        int len = s.length();
        int start = 0;
        while (start < len) {
            if (s[start] == '#') {
                int count = stoi(countStr);
                start++;
                string x = "";
                for (int i=0; i<count; i++) {
                    x+=s[start + i];
                }
                res.push_back(x);
                start+=count;
                countStr = "";
            } else {
                countStr+=s[start];
                start++;
            }
        }
        return res;
    }
};
