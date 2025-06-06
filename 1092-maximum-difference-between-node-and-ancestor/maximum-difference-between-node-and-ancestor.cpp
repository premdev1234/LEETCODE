class Solution {
public:
    int dfs(TreeNode* root, int minval, int maxval) {
        if (!root) return abs(maxval - minval);
        
        minval = min(minval, root->val);
        maxval = max(maxval, root->val);
        
        int left = dfs(root->left, minval, maxval);
        int right = dfs(root->right, minval, maxval);
        
        return max(left, right);
    }

    int maxAncestorDiff(TreeNode* root) {
        return move(dfs(root, root->val, root->val));
    }
};
