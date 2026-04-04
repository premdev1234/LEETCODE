class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        
        vector<vector<int>> dp(n, vector<int>(26));
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        int processed = 0, ans = 0;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            processed++;
            
            dp[u][colors[u] - 'a']++;
            ans = max(ans, dp[u][colors[u] - 'a']);
            
            for (int v : adj[u]) {
                for (int c = 0; c < 26; c++) {
                    dp[v][c] = max(dp[v][c], dp[u][c]);
                }
                if (--indegree[v] == 0) q.push(v);
            }
        }
        
        return processed == n ? ans : -1;
    }
};