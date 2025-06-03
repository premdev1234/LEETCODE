class Solution {
public:
    // Returns pair: {max if not robbed, max if robbed}
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // If we rob current node, cannot rob children
        int rob = root->val + left.first + right.first;

        // If we don't rob current node, we can choose max of rob or not rob for children
        int not_rob = max(left.first, left.second) + max(right.first, right.second);

        return {not_rob, rob};
    }

    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};
