class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> occupancy(10001,0);
        int n = (int)trips.size();
        for(int i = 0 ; i < n ; ++i){
            int p = trips[i][0] , f = trips[i][1] , t =trips[i][2] ;
            occupancy[f] += p ;
            occupancy[t] -= p ; 
        }
        int curr = 0 ;
        for(int x : occupancy){
            curr += x ;
            if( curr > capacity){
                return false;
            }
        }
        return true;

    }
};