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
    vt f(int s, int e, map<pair<int,int>, vector<TreeNode*>>&dp){
        vt ans;

        if(s > e) return {nullptr};

        if(dp.find({s,e}) != dp.end()) return dp[{s,e}];

        for(int i = s; i<= e; i++){
            vector<TreeNode*> lefti = f(s,i-1,dp);
            vector<TreeNode*> righti = f(i+1, e, dp);

            for(auto node : lefti){
                for(auto node1 : righti){
                    TreeNode* root = new TreeNode(i,node, node1);
                    ans.push_back(root);
                }
            }
        }

        dp[{s,e}] = ans;
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int,int>, vector<TreeNode*>>dp;

        return f(1,n, dp);
    }
};