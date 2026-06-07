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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diameter = leftHeight + rightHeight;

        int sub = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
        return max(diameter, sub);
    }

private:
    int height(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
};
