class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k%2 == 0 || k%5 == 0) return -1 ;
        int ans = 1 , rem = 1%k ;
        if(rem == 0) return 1 ;
        vector<bool> rems(k,false);
        rem = true ;
        for(int i = 1 ; i <= k ; ++i){
            rem = (rem*10 + 1)%k ;
            if(rems[rem])return -1 ;
            ans++ ;
            if(rem == 0) return ans ; 
        }
        return -1;
    }
};