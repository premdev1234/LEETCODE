/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Helper to perform preorder traversal
    void preorder(TreeNode* root, string& s) {
        if (!root) return;
        s += to_string(root->val) + '#';
        preorder(root->left, s);
        preorder(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encoded;
        preorder(root, encoded);
        return encoded;
    }

    // Helper to parse string into preorder array
    vector<int> parsePreorderString(const string& s) {
        vector<int> res;
        stringstream ss(s);
        string token;
        while (getline(ss, token, '#')) {
            if (!token.empty()) res.push_back(stoi(token));
        }
        return res;
    }

    // Recursively build BST from preorder using upper bound
    TreeNode* buildBST(vector<int>& preorder, int& i, int bound) {
        if (i >= preorder.size() || preorder[i] > bound) return nullptr;

        int val = preorder[i++];
        TreeNode* node = new TreeNode(val);
        node->left = buildBST(preorder, i, val);
        node->right = buildBST(preorder, i, bound);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> preorder = parsePreorderString(data); // <-- fix: use `data`, not `s`
        int idx = 0;
        return buildBST(preorder, idx, INT_MAX);
    }
};
