class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> stk;

        int n = heights.size();
        for (int i=0; i<n; i++) {
            int start = i;
            while (!stk.empty() && stk.top().second > heights[i]) {
                pair<int, int> top = stk.top();
                int height = top.second;
                int index = top.first;
                maxArea = max(maxArea, height * (i - index));
                start = index;
                stk.pop();
            }
            stk.push({start, heights[i]});
        }

        while (!stk.empty()) {
            int index = stk.top().first;
            int height = stk.top().second;
            maxArea = max(maxArea, height * (n-index));
            stk.pop();
        }
        return maxArea;
    }
};
