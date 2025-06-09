class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> red(n), blue(n);
        for (auto& e : redEdges) red[e[0]].push_back(e[1]);
        for (auto& e : blueEdges) blue[e[0]].push_back(e[1]);

        vector<vector<int>> dist(n, vector<int>(2, -1)); // dist[node][color]: 0 = red, 1 = blue
        queue<tuple<int, int, int>> q; // node, color, distance

        q.push({0, 0, 0}); // red
        q.push({0, 1, 0}); // blue
        dist[0][0] = dist[0][1] = 0;

        while (!q.empty()) {
            auto [u, color, d] = q.front(); q.pop();
            auto& next = (color == 0) ? blue : red; // alternate color
            int nextColor = 1 - color;

            for (int v : next[u]) {
                if (dist[v][nextColor] == -1) {
                    dist[v][nextColor] = d + 1;
                    q.push({v, nextColor, d + 1});
                }
            }
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            if (dist[i][0] == -1 && dist[i][1] == -1) ans[i] = -1;
            else if (dist[i][0] == -1) ans[i] = dist[i][1];
            else if (dist[i][1] == -1) ans[i] = dist[i][0];
            else ans[i] = min(dist[i][0], dist[i][1]);
        }
        return move(ans);
    }
};