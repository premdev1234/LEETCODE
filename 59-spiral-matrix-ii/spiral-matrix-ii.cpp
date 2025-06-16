class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top = 0  , left  =0 , bottom =  n-1 , right = n-1 ;
        vector<vector<int>> a(n,vector<int>(n));
        int val =  1 ;
        while(top <= bottom and left <= right){
            for(int i = left ; i<= right ; i++) a[top][i] = val++;
            top++;
            for(int i = top ; i <= bottom ; i++) a[i][right] =  val++;
            right--;
            for(int i =  right ; i >= left ; --i) a[bottom][i] =  val++;
            bottom--;
            for(int i = bottom ; i >= top ; --i) a[i][left] = val++;
            left++;
        }
        return move(a);
    }
};