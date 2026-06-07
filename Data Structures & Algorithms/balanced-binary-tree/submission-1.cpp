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
    bool isBalanced(TreeNode* root) {
        pair<int, bool> res = height(root);
        return res.second;    
    }

    pair<int, bool> height(TreeNode* node) {
        if (!node) return {0, true};
        pair<int, bool> left = height(node->left);
        pair<int, bool> right = height(node->right);
        bool balanced =  left.second && right.second && abs(left.first-right.first) <= 1;
        int height = max(left.first, right.first);
        return {1 + height, balanced};
    }
};
