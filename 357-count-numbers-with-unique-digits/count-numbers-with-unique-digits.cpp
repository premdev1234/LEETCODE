class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int ans = 10, prod = 9, cap = 9;
        for(int i = 2; i <= n && cap > 0; i++) {
            prod *= cap;
            ans += prod;
            cap--;
        }
        return ans;
    }
};
