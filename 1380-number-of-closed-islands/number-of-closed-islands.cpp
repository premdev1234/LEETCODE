class Solution {
public:
    void dfs(int i, int j , vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==1)return;
        grid[i][j]=1;
        int dx[]={1,0,-1,0};
        int dy[]={0,-1,0,1};
        for(int k=0;k<4;k++){
            int row = i+dx[k];
            int col = j + dy[k];
            dfs(row,col,grid);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0)dfs(i,0,grid);
            if(grid[i][m-1]==0)dfs(i,m-1,grid);
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==0)dfs(0,i,grid);
            if(grid[n-1][i]==0)dfs(n-1,i,grid);
        }
        int ans=0;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    dfs(i,j,grid);
                    ans++;
                }
                
            }
        }
        return ans;
    }
};