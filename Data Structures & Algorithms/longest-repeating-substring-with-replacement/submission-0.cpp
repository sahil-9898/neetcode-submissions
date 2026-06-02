class Solution {

private:
    int getMax(unordered_map<char, int> &mp) {
        int m = -1;
        for(auto p: mp) {
            m = max(p.second, m);
        }
        return m;
    }

public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int res = 0;
        int left = 0;

        for (int right=0; right<s.length(); right++) {
            count[s[right]]++;
            while ((right - left + 1) - getMax(count) > k) {
                count[s[left]]--;
                left++;
            }

            res = max(res, right - left + 1);
        }
        return res;
    }
};
