class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(0, curr, nums);
        return res;
    }

private:
    void backtrack(int i, vector<int>& curr, vector<int>& nums) {
        if (i==nums.size()) {
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        backtrack(i+1, curr, nums);
        curr.pop_back();
        while (i+1<nums.size() && nums[i] == nums[i+1]) {
            i++;
        }
        backtrack(i+1, curr, nums);
    }
};
