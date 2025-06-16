class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));

        int x=0;
        int y=0;
        int dx=1;
        int dy=0;

        for (int i=0;i<n*n;i++){
            res[y][x]=i+1;

            if(!(0<=x+dx && x+dx < n && 0<=y+dy && y+dy<n && res[y+dy][x+dx]==0)){
                int temp = dx;
                dx= -dy;
                dy = temp;
            }

            x=x+dx;
            y=y+dy;
        }
        
        return res;
    }
};