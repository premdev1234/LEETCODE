class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        constexpr int RED = 0, BLUE = 1;
        unordered_map<int, vector<pair<int, int>>> graph; // u -> [(v, color)]
        
        for (const auto &edge : redEdges) graph[edge[0]].push_back({edge[1], RED});
        for (const auto &edge : blueEdges) graph[edge[0]].push_back({edge[1], BLUE});

        vector<vector<int>> dist(n, vector<int>(2, 1e9)); // dist[node][color]
        dist[0][RED] = dist[0][BLUE] = 0;

        queue<tuple<int, int, int>> q; // (node, color, distance)
        q.emplace(0, RED, 0);
        q.emplace(0, BLUE, 0);

        while (!q.empty()) {
            auto [u, lastColor, d] = q.front(); q.pop();

            for (auto &[v, color] : graph[u]) {
                if (color != lastColor && d + 1 < dist[v][color]) {
                    dist[v][color] = d + 1;
                    q.emplace(v, color, d + 1);
                }
            }
        }

        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            int shortest = min(dist[i][RED], dist[i][BLUE]);
            res[i] = (shortest == 1e9 ? -1 : shortest);
        }
        return res;
    }
};
