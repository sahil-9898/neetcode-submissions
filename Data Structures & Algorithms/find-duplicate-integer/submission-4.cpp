class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i: nums) {
            int index = abs(i) - 1;
            if (nums[index] < 0) return abs(i);
            nums[index] *= -1;
        }
        return -1;
    }
};
