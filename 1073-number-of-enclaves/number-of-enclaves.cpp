class Solution {
public:
    vector<int> parent;
    int rows, cols;

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union by parent
    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry)
            parent[rx] = ry;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        parent.resize(rows * cols);

        // Initialize parent to self
        for (int i = 0; i < rows * cols; ++i)
            parent[i] = i;

        // Directions: up, down, left, right
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Step 1: Union connected land cells
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    int id = i * cols + j;
                    for (auto& [dx, dy] : dirs) {
                        int ni = i + dx, nj = j + dy;
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && grid[ni][nj] == 1) {
                            int nid = ni * cols + nj;
                            unite(id, nid);
                        }
                    }
                }
            }
        }

        // Step 2: Mark all root nodes connected to border
        unordered_set<int> borderRoots;
        for (int i = 0; i < rows; ++i) {
            for (int j : {0, cols - 1}) {
                if (grid[i][j] == 1)
                    borderRoots.insert(find(i * cols + j));
            }
        }
        for (int j = 0; j < cols; ++j) {
            for (int i : {0, rows - 1}) {
                if (grid[i][j] == 1)
                    borderRoots.insert(find(i * cols + j));
            }
        }

        // Step 3: Count land cells not in any border-rooted set
        int enclaves = 0;
        for (int i = 1; i < rows - 1; ++i) {
            for (int j = 1; j < cols - 1; ++j) {
                if (grid[i][j] == 1 && !borderRoots.count(find(i * cols + j)))
                    enclaves++;
            }
        }

        return enclaves;
    }
};
