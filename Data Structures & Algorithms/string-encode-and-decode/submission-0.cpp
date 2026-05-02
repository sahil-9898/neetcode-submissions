class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (auto s: strs) {
            encoded += to_string(s.length());
            encoded += s;
        }
        encoded += "#";
        return encoded;
    }
    vector<string> decode(string s) {
        vector<string> res;
        int index = 0;
        while(true) {
            if (s[index] == '#') break;
            string part;
            int len = s[index++] - '0';
            int right = index + len;
            while(index < right) {
                part += s[index++];
            }
            res.push_back(part);
        }
        return res;
    }
};
