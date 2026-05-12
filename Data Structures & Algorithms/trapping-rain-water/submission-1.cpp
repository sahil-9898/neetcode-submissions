class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxl = height[0], maxr = height[n-1];
        int res = 0;
        int left = 0, right = n-1;
        while (left < right) {
            if (height[left] < height[right]) {
                left++;
                int x = maxl - height[left];
                if (x > 0) res+=x;
                maxl = max(maxl, height[left]);
            } else {
                right--;
                int x = maxr - height[right];
                if (x > 0) res+=x;
                maxr = max(maxr, height[right]);
            }
        }
        return res;
    }
};
