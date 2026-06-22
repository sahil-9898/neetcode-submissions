class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<bool> picked(nums.size(), false);
        backtrack(nums, curr, picked);
        return res;
    }

private:
    void backtrack(vector<int>& nums, vector<int>& curr, vector<bool>& picked) {
        if (curr.size()==nums.size()) {
            res.push_back(curr);
            return;
        }

        for (int i=0;i<nums.size();i++) {
            if (!picked[i]) {
                curr.push_back(nums[i]);
                picked[i] = true;
                backtrack(nums, curr, picked);
                curr.pop_back();
                picked[i] = false;
            }
        }
    }
};
