class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> res;
        int numsSize = nums.size();
        for (int i=0;i<numsSize;i++) {
            int difference = target - nums[i];
            if (map.find(difference) != map.end()) {
                res.push_back(i);
                res.push_back(map[difference]);
                sort(res.begin(), res.end());
                return res;
            } 
            map[nums[i]] = i;
        }
    }
};
