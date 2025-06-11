class Solution {
public:
    struct DSU {
        vector<int> parent;
        DSU(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            if (x != parent[x]) parent[x] = find(parent[x]);
            return parent[x];
        }

        bool unite(int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra == rb) return false;
            parent[rb] = ra;
            return true;
        }
    };

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<tuple<int, int, int>> edges;

        // Build all edges
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.emplace_back(dist, i, j);
            }
        }

        // Sort by distance
        sort(edges.begin(), edges.end());

        DSU dsu(n);
        int res = 0, used = 0;

        for (auto &[cost, u, v] : edges) {
            if (dsu.unite(u, v)) {
                res += cost;
                used++;
                if (used == n - 1) break;
            }
        }

        return res;
    }
};
