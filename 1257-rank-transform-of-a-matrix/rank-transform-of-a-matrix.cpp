class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> answer(m, vector<int>(n, 0));
        map<int, vector<pair<int, int>>> valueMap;
        
        // Group cells by their values
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                valueMap[matrix[i][j]].push_back({i, j});
            }
        }
        
        vector<int> rowMax(m, 0), colMax(n, 0);
        
        // Process values from smallest to largest
        for (auto& [value, cells] : valueMap) {
            UnionFind uf(m + n);
            
            // Union cells with the same value in the same row or column
            for (auto& [i, j] : cells) {
                uf.unite(i, j + m);
            }
            
            // Find the maximum rank for each group
            unordered_map<int, int> groupRank;
            for (auto& [i, j] : cells) {
                int group = uf.find(i);
                groupRank[group] = max({groupRank[group], rowMax[i] + 1, colMax[j] + 1});
            }
            
            // Assign ranks and update row/column maximums
            for (auto& [i, j] : cells) {
                int rank = groupRank[uf.find(i)];
                answer[i][j] = rank;
                rowMax[i] = max(rowMax[i], rank);
                colMax[j] = max(colMax[j], rank);
            }
        }
        
        return answer;
    }
    
private:
    class UnionFind {
    public:
        UnionFind(int n) : parent(n), rank(n, 0) {
            for (int i = 0; i < n; i++) parent[i] = i;
        }
        
        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        
        void unite(int x, int y) {
            int px = find(x), py = find(y);
            if (px == py) return;
            if (rank[px] < rank[py]) parent[px] = py;
            else if (rank[px] > rank[py]) parent[py] = px;
            else {
                parent[py] = px;
                rank[px]++;
            }
        }
        
    private:
        vector<int> parent, rank;
    };
};