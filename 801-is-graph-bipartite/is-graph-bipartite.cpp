class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<char> color(n, -1);  // -1 means uncolored

    for (int start = 0; start < n; ++start) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : graph[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];  // alternate color
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        // Same color on both ends → not bipartite
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

};