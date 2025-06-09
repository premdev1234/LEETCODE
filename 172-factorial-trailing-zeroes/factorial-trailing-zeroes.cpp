class Solution {
public:
    int trailingZeroes(int n) {
        int exp = 0;
        while (n >= 5) {
            n /= 5;
            exp += n;
        }
        return exp;
    }
};
