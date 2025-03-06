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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> stk;
        int i = 0, n = traversal.size();

        while (i < n) {
            int depth = 0;

            // Count dashes to determine depth
            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }

            // Extract node value
            int value = 0;
            while (i < n && isdigit(traversal[i])) {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }

            // Create new TreeNode
            TreeNode* node = new TreeNode(value);

            // If depth == stack size, it means node is the left child
            if (depth == stk.size()) {
                if (!stk.empty()) stk.top()->left = node;
            } 
            // If depth < stack size, pop the stack to find correct parent
            else {
                while (stk.size() > depth) stk.pop();
                stk.top()->right = node;
            }

            // Push current node onto stack
            stk.push(node);
        }

        // Root node is at the bottom of the stack
        while (stk.size() > 1) stk.pop();
        return stk.top();
    }
};
