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
 #define vt vector<TreeNode*> 
class Solution {
public:
    vt buildtrees(int start , int end){
        vt trees ;
        if(start > end){
            trees.push_back(nullptr);
            return trees;
        }
        for(int node =  start ; node <= end ; ++node){
            vt lefttree =  buildtrees(start,node-1);
            vt righttree =  buildtrees(node+1,end);
            for(TreeNode* left : lefttree){
                for(TreeNode* right : righttree){
                    TreeNode* root =  new TreeNode(node);
                    root->left =  left;
                    root->right =  right;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
    vt generateTrees(int n) {
        if(n == 0) return {};
        return buildtrees(1,n);
    }
};