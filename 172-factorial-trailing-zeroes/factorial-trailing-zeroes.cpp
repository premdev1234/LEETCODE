class Solution {
public:
    int exponent(int n, int prime) {
        int exp = 0;
        while (n >= prime) {
            n /= prime;
            exp += n;
        }
        return exp;
    }

    int trailingZeroes(int n) {
        return exponent(n, 5);  // since 2s are more abundant than 5s
    }
};
