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
    int itr = 0 , ans =-1;
    void inorder(TreeNode * root, int k){
        if(!root) return;
        if(itr==k) return;
        inorder(root->left,k);
        if(itr==k) return;
        ans=root->val;
        itr++;
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        root->left=NULL;
        root->right=NULL;
        return ans;
    }
};