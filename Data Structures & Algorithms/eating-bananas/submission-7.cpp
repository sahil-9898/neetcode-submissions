class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = -1;
        for (auto x: piles) {
            right = max(right, x);
        }

        int left = 1;
        int currResult = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int totalTime = 0;
            for (int x: piles) {
                totalTime += (int)ceil((double)x/mid);
            }
            if (totalTime > h) {
                left = mid + 1;
            }
            else if (totalTime <= h) {
                right = mid - 1;
                currResult = min(currResult, mid);
            }
        }
        return currResult;
    }
};
