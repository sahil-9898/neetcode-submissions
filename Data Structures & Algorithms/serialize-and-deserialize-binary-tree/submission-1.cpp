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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> preorder;
        dfsSerialize(root, preorder);
        return join(preorder, ",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> preorder = split(data, ',');
        int i = 0;
        return dfsDeserialize(preorder, i);
    }

private:
    void dfsSerialize(TreeNode* root, vector<string>& preorder) {
        if (!root) {
            preorder.push_back("N");
            return;
        }
        preorder.push_back(to_string(root->val));
        dfsSerialize(root->left, preorder);
        dfsSerialize(root->right, preorder);
    }

    TreeNode* dfsDeserialize(vector<string>& preorder, int& i) {
        if (preorder[i] == "N") {
            i++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(preorder[i]));
        i++;
        node->left = dfsDeserialize(preorder, i);
        node->right = dfsDeserialize(preorder, i);
        return node;
    }

    string join(const vector<string> &s, const string &delim) {
        ostringstream ss;
        for (auto &i: s) {
            if (&i != &s[0]) {
                ss << delim;
            }
            ss << i;
        }
        return ss.str();
    }

    vector<string> split(const string& s, char delim) {
        vector<string> res;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            res.push_back(item);
        }
        return res;
    }
};
