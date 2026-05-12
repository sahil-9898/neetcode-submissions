class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxl = height[0], maxr = height[n-1];
        int res = 0;
        int left = 0, right = n-1;
        while (left < right) {
            if (maxl < maxr) {
                left++;
                maxl = max(maxl, height[left]);
                res += maxl - height[left];
            } else {
                right--;
                maxr = max(maxr, height[right]);
                res += maxr - height[right];
            }
        }
        return res;
    }
};
