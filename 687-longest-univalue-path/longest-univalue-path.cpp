class Solution {
public:
    int maxLen = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        int leftPath = 0, rightPath = 0;

        if (root->left && root->left->val == root->val)
            leftPath = left + 1;

        if (root->right && root->right->val == root->val)
            rightPath = right + 1;

        // Update the global max if the path through root is longer
        maxLen = max(maxLen, leftPath + rightPath);

        // Return the max path length to parent
        return max(leftPath, rightPath);
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return maxLen;
    }
};
