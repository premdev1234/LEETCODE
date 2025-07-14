enum color { WHITE, GRAY, BLACK };

class Solution {
public:
    bool dfs(int node, vector<int>& color, vector<vector<int>>& graph) {
        color[node] = GRAY;

        for (int neighbor : graph[node]) {
            if (color[neighbor] == WHITE) {
                if (dfs(neighbor, color, graph))
                    return true; // cycle detected
            } else if (color[neighbor] == GRAY) {
                return true; // back edge found → cycle
            }
        }

        color[node] = BLACK;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, WHITE);
        vector<int> result;

        for (int i = 0; i < n; ++i) {
            if (!dfs(i, color, graph)) {
                result.push_back(i); // safe node
            }
        }

        return result; // already in sorted order due to increasing i
    }
};
