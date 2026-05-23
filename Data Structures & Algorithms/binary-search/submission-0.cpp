class Solution {
public:
    int binarySearch(int start, int end, int target, vector<int>& nums) {
        if (start > end) return -1;

        int mid = (start + end) / 2;

        if (nums[mid] == target) return mid;

        if (nums[mid] < target) {
            return binarySearch(mid + 1, end, target, nums);
        }
        return binarySearch(start, mid-1, target, nums);
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(0, nums.size() - 1, target, nums);
    }
};
