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
        return dfs(root).first;
    }

private:
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {INT_MIN, 0};
        auto [leftMax, leftSingle] = dfs(root->left);
        auto [rightMax, rightSingle] = dfs(root->right);
        int maxSingle = max({root->val, root->val + leftSingle, root->val + rightSingle});
        int maxTop = max(leftMax, max(rightMax, maxSingle));
        return {max(maxTop, root->val + leftSingle + rightSingle), maxSingle};
    }
};