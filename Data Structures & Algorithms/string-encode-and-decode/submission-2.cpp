class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        if (strs.size() == 0) return encoded;
        for (auto s: strs) {
            encoded += to_string(s.length());
            encoded += s;
        }
        encoded += "#";
        return encoded;
    }
    vector<string> decode(string s) {
        vector<string> res;
        if (s == "") return res;
        int index = 0;
        while(true) {
            string part;
            int len = s[index++] - '0';
            int right = index + len;
            while(index < right) {
                part += s[index++];
            }
            res.push_back(part);
            if (s[index] == '#') break;
        }
        return res;
    }
};
