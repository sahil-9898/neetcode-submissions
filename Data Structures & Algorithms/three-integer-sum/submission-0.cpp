class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = nums.size();
        vector<vector<int>> res;
        for (int i=0; i<l-2; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            int first = nums[i];
            int target = -first;
            int left = i+1;
            int right = l-1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left-1]) left++;
                    while (left < right && nums[right] == nums[right+1]) right--;
                }
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return res;
    }
};
