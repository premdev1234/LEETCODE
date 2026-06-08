class Solution {
public:
    int integerReplacement(int num) {
        int steps = 0 ;
        long long n = num ;
        while(n != 1){
            if( n&1) {
                if(n == 3) n-- ;
                else n += (n%4 == 3 ? 1 : -1);
            } else n >>= 1 ;
            steps++;
        }
        return steps;
    }
};