class Solution {
    vector<vector<int>> res;
    vector<int> curr;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0, 0, nums, target);
        return res;
    }
private:
    void dfs(int i, int total, vector<int>& nums, int target) {
        if (total == target) {
            res.push_back(vector<int>(curr.begin(), curr.end()));
            return;
        }
        if (total > target || i >= nums.size()) {
            return;
        }

        curr.push_back(nums[i]);
        dfs(i, total + nums[i], nums, target);
        curr.pop_back();
        dfs(i+1, total, nums, target);
    }
};
