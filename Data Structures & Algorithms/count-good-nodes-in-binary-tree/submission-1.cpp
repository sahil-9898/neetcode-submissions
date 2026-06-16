/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int big = INT_MIN;
        int res = 0;
        dfs(root, big, res);
        return res;
    }

    void dfs(TreeNode* root, int big, int &res) {
        if (!root) return;
        if (root->val >= big) {
            res++;
        }
        dfs(root->left, max(root->val, big), res);
        dfs(root->right, max(root->val, big), res);
    }
};
