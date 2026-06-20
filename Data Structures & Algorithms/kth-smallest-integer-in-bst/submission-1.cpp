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
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        int curr = 0;
        inorder(root, res, k, curr);
        return res;
    }

    void inorder(TreeNode* root, int &res, int k, int &curr) {
        if (!root) return;
        inorder(root->left, res, k,curr);
        curr++;
        if (curr == k) res = root->val;
        inorder(root->right, res, k, curr);
    }
};
