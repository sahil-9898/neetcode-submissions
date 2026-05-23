class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxSpeed = -1;
        for (auto x: piles) {
            maxSpeed = max(maxSpeed, x);
        }
        for (int speed=1; speed<=maxSpeed; speed++) {
            int totalTime = 0;
            for (auto x: piles) {
                totalTime += (int)ceil((double)x/speed);
                if (totalTime > h) {
                    break;
                }
            }
            if (totalTime <= h) {
                return speed;
            }
        }
        return -1;
    }
};
