class Solution {
    bool dfs(int node, const vector<vector<int>>& graph, vector<int>& color) {
        for (int neighbor : graph[node]) {
            if (color[neighbor] == -1) {
                color[neighbor] = 1 - color[node]; // assign opposite color
                if (!dfs(neighbor, graph, color)) {
                    return false;
                }
            } else if (color[neighbor] == color[node]) {
                return false; // same color neighbor detected
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                color[i] = 0; // start coloring with 0
                if (!dfs(i, graph, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};

