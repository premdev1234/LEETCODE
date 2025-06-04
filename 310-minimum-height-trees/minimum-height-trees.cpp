class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        // Step 1: Build the graph
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        // Step 2: Initialize first layer of leaves
        queue<int> q;
        for (int i = 0; i < n; ++i)if (degree[i] == 1) q.push(i);

        // Step 3: Remove leaves layer-by-layer
        vector<int> lastLayer;
        while (!q.empty()) {
            int size = q.size();
            lastLayer.clear();
            for (int i = 0; i < size; ++i) {
                int node = q.front(); q.pop();
                lastLayer.push_back(node);
                for (int neighbor : adj[node]) {
                    if (--degree[neighbor] == 1) q.push(neighbor);
                }
            }
        }

        return lastLayer; // 1 or 2 center nodes
    }
};
