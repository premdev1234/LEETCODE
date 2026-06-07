class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int n = (int)points.size();
        int best = 0 ;
        for(int i = 0 ; i < n-1 ; ++i){
            int X = points[i][0] , Y = points[i][1];
            for(int j = i + 1 ; j < n ; ++j){
                int x2 = points[j][0] , y2 = points[j][1] , x1 = X , y1 = Y;
                bool a = false , b = false ;
                int l , m ;
                for(int k = 0 ; k < n ; k++){
                    if(k == i || k == j){
                        continue;
                    }
                    int x = points[k][0] , y = points[k][1];
                    if(x == x1 && y == y2) a = true , l = k;
                    if(x == x2 && y == y1) b = true , m = k;
                    if( a && b) break;
                }
                if(!(a&b)){
                    continue;
                }
                int temp = max(x1,x2);
                x1 = min(x1,x2);
                x2 = temp ;
                temp = max(y1,y2);
                y1 = min(y1,y2);
                y2 = temp ;
                bool possible = true ;
                for(int k = 0 ; k < n ; k++){
                    if(k == i || k == j || k == l || k == m){
                        continue;
                    }
                    int x = points[k][0] , y = points[k][1];
                    bool A = (x <= x2 && x >= x1) , B = (y1 <= y && y <= y2) ;
                    if(A&B){
                        possible = false;
                        break;
                    }
                }
                if(!possible)continue;
                else best = max(best,((x2-x1)*(y2-y1)));
            }
        }
        return best == 0 ? -1 : best;
    }
};