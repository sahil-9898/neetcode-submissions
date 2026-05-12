class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        int l = heights.size();
        int left = 0;
        int right = l-1;
        while (left < right) {
            int length = right - left;
            int breadth = min(heights[left], heights[right]);
            res = max(res, length*breadth);
            if (heights[left] < heights[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return res;
    }
};
