class Solution {
public:
    bool dfs(int node, bitset<10001>& visited, bitset<10001>& onPath,
             vector<bool>& safe, vector<vector<int>>& graph) {
        visited[node] = true;
        onPath[node] = true;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, visited, onPath, safe, graph)) {
                    return true;
                }
            } else if (onPath[neighbor]) {
                return true;
            }
        }

        onPath[node] = false;
        safe[node] = true;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        bitset<10001> visited, onPath;
        vector<bool> safe(n, false);

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, visited, onPath, safe, graph);
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (safe[i]) result.push_back(i);
        }
        return result;
    }
};
