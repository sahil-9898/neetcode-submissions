class Solution {

    vector<vector<int>> res;
    vector<int> curr;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, 0, candidates, target);
        return res;
    }

private:
    void dfs(int i, int total, vector<int>& candidates, int target) {
        if (total == target) {
            res.push_back(curr);
            return;
        }
        if (total > target || i >= candidates.size()) {
            return;
        }

        curr.push_back(candidates[i]);
        dfs(i + 1, total + candidates[i], candidates, target);
        curr.pop_back();
        while (i + 1 < candidates.size() && candidates[i] == candidates[i+1]) {
            i++;
        }
        dfs(i + 1, total, candidates, target);
    }
};
