class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> inMST(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;  // min heap
        pq.emplace(0, 0); // cost, point index
        int res = 0, edgesUsed = 0;
        while (edgesUsed < n) {
            auto [cost, u] = pq.top(); pq.pop();
            if (inMST[u]) continue;

            inMST[u] = true;
            res += cost;
            edgesUsed++;

            for (int v = 0; v < n; ++v) {
                if (!inMST[v]) {
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    pq.emplace(dist, v);
                }
            }
        }

        return res;
    }
};
