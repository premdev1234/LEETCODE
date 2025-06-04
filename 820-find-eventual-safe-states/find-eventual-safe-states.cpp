class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> outdegree(n, 0);
        
        // Build reverse graph and outdegree count
        for (int u = 0; u < n; ++u) {
            for (int v : graph[u]) {
                reverseGraph[v].push_back(u);
            }
            outdegree[u] = graph[u].size();
        }

        queue<int> q;
        // Start from terminal nodes (outdegree 0)
        for (int i = 0; i < n; ++i)
            if (outdegree[i] == 0) q.push(i);
        
        vector<bool> safe(n, false);
        while (!q.empty()) {
            int node = q.front(); q.pop();
            safe[node] = true;
            for (int parent : reverseGraph[node]) {
                if (--outdegree[parent] == 0)
                    q.push(parent);
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i)
            if (safe[i]) result.push_back(i);
        
        return result;
    }
};
