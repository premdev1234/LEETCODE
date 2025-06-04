class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, bitset<201>& visited) {
        visited[city] = true;
        for (int neighbor = 0; neighbor < isConnected.size(); ++neighbor) {
            if (isConnected[city][neighbor] && !visited[neighbor]) {
                dfs(neighbor, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        bitset<201> visited; 

        int provinceCount = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, isConnected, visited);
                provinceCount++;
            }
        }
        return provinceCount;
    }
};
