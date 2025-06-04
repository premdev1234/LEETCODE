class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) {
            int u = f[0], v = f[1], w = f[2];
            adj[u].emplace_back(v, w);
        }

        // (cost, city, stops)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, src, 0);

        vector<int> minStops(n, INT_MAX);

        while (!pq.empty()) {
            auto [cost, u, stops] = pq.top(); pq.pop();
            if (u == dst) return cost;
            if (stops > k || stops >= minStops[u]) continue;
            minStops[u] = stops;
            for (auto& [v, w] : adj[u]) {
                pq.emplace(cost + w, v, stops + 1);
            }
        }

        return -1;
    }
};
