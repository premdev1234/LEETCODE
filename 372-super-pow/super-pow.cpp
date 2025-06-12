class Solution {
public:
    const int mod = 1337;

    int modpow(int a, int b) {
        int res = 1;
        a %= mod;
        while (b) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        int res = 1;
        for (int digit : b) {
            // res = modpow(res, 10);          // res = res^10 % mod
            res = (modpow(res, 10) * modpow(a, digit)) % mod; // res *= a^digit % mod
        }
        return res;
    }
};
