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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            int right = NULL;
            for (int i=0;i<n;i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node) {
                    right = node->val;
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if (right != NULL) {
                res.push_back(right);
            }
        }
        return res;
    }
};
