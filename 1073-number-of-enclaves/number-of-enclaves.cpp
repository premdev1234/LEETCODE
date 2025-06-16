class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;

        for(int i = 0; i<m; i++)
            for(int j = 0; j<n; j++)
                if(i == 0 || j == 0 || i == m-1 || j == n-1)
                    if(grid[i][j] == 1)
                        q.push({i,j}), grid[i][j] = 0;


        vector<int>dir = {0, -1 , 0 , 1 , 0};

        while(!q.empty()){
            pair<int,int> curr = q.front();
            int i = curr.first;
            int j = curr.second;
            q.pop();

            for(int k = 0 ; k < 4; k++){
                int ni = i + dir[k];
                int nj = j + dir[k+1];

                if(ni >= 0 && ni < m && nj < n && nj >= 0 && grid[ni][nj]){
                    q.push({ni,nj});
                    grid[ni][nj] = 0;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                ans += grid[i][j];
            }
        }

        return ans;
    }
};