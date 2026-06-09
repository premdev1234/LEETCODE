class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = (int)colsum.size();
        vector<vector<int>> ans(2,vector<int>(n,0));
        // if colsum[i] = 2 then both are 1 , 
        int sum = 0 ;
        for(int x : colsum)sum+=x;
        if(sum != (upper + lower)) return {};
        int u = upper , l = lower , s = sum ;
        for(int i = 0 ; i < n ; ++i){
            if(colsum[i] == 2){
                ans[0][i] = 1 ;
                ans[1][i] = 1 ;
                s -=2 ;
                u--;
                l--;
            }else if(colsum[i] == 0){
                ans[0][i] = 0 ;
                ans[1][i] = 0 ;
            } else {
                if(u >= l){
                    ans[0][i] = 1 ;
                    ans[1][i] = 0;
                    --u , --s ;
                } else {
                    ans[0][i] = 0 ;
                    ans[1][i] = 1 ;
                    --l , --s ;
                }
            }
        }
        if(l!=0 || u != 0 || s != 0){
            return {};
        }
        return ans ;
    }
};