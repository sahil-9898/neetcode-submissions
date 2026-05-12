class Solution {
public:
    int trap(vector<int>& height) {
        int l = height.size();
        vector<int> maxl(l);
        vector<int> maxr(l);
        int temp = 0;
        for (int i=0; i<l; i++) {
            maxl[i] = temp;
            temp = max(height[i], temp); 
        }
        temp = 0;
        for (int i=l-1; i>=0; i--) {
            maxr[i] = temp;
            temp = max(temp, height[i]);
        }
        int res = 0;
        for (int i=0; i<l; i++) {
            int x = min(maxr[i], maxl[i]) - height[i];
            if (x > 0) res += x;
        }

        return res;
    }
};
