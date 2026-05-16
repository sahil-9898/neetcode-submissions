class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);

        for (int i=0; i<n; i++) {
            int count = 1;
            int j = i+1;
            while(j<n && temperatures[j] <= temperatures[i]) {
                count++;
                j++;
            }
            if (j!=n) {
                res[i] = count;
            }
        }
        return res;
    }
};
