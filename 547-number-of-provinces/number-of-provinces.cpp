class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0); // parent[i] = i

        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };

        auto unite = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY) return;
            if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
            else if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        };

        // Merge connected cities
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (isConnected[i][j])
                    unite(i, j);

        // Count unique roots
        unordered_set<int> provinces;
        for (int i = 0; i < n; ++i)
            provinces.insert(find(i));

        return provinces.size();
    }
};
