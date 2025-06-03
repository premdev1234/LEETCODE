class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (left < right)  right = right & (right - 1);  // Drop the lowest set bit
        return right;  // Now left == right at the most significant common prefix
        /* BOTH SHIFT
        int shift = 0;
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift;
        /* BRUTE FORCE ==> TLE
        int result = 0 , n =  right-left+1;
        for(int i = 0 ; i < 32 ;i++){
            int sum = 0 ;
            for(int j = left ; j <= right ;j++){
                if(j&(1<<i)) sum++;
            }
            if(sum == n) result |= (1 << i);
        }
        return result;*/
    }
};