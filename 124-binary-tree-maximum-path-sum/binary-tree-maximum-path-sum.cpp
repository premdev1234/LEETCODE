#include <bits/stdc++.h>
using namespace std;

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
    int maxPathSum(TreeNode* root) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }

private:
    int dfs(TreeNode* root, int& ans) {
        if (!root) return 0;
        int leftSingle = max(0, dfs(root->left, ans));
        int rightSingle = max(0, dfs(root->right, ans));
        ans = max(ans, leftSingle + rightSingle + root->val);
        return max(leftSingle, rightSingle) + root->val;
    }
};