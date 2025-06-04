class Solution {
public:
    int parent[1001];

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unionSet(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        parent[px] = py;
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (int i = 1; i <= 1000; ++i) parent[i] = i;
        for (auto &e : edges) {
            if (!unionSet(e[0], e[1]))
                return e;
        }
        return {};
    }
};
