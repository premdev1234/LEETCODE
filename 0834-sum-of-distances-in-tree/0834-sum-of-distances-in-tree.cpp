class Solution {
public:
    void dfs(int node , int parent , std::vector<int>&dp , std::vector<int>&sub , int n , std::vector<std::vector<int>>&graph){
        for(int child : graph[node]){
            if(child != parent){
                dfs(child,node,dp,sub,n,graph);
                sub[node]+=sub[child];
                dp[node] += (dp[child]+sub[child]);
            }
        }
    }
    void dfs1(int node , int parent , std::vector<int>&ans , std::vector<int>&sub , int n , std::vector<std::vector<int>>&graph){
        for(int child : graph[node]){
            if(child != parent){
                ans[child] = ans[node] - sub[child] + (n - sub[child]);
                dfs1(child,node,ans,sub,n,graph);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> sub(n, 1) , dp(n, 0) , ans(n);
        dfs(0, -1 , dp , sub , n , graph);
        ans[0] = dp[0];
        dfs1(0, -1, ans , sub , n ,graph);
        return move(ans) ;
    }
};