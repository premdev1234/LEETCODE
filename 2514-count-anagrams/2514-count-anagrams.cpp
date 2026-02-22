static const int mod = 1'000'000'007;
static const int N = 100000 + 5;
inline int add(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    if (a < 0) a += mod;
    return a;
}
inline int mul(int a, int b) {return int((int64_t)a * b % mod);}
int binpow(int b, int e) {
    int r = 1;
    while (e) {
        if (e & 1)r = mul(r, b);
        b = mul(b, b);
        e >>= 1;              
    }
    return r;
}
inline int inv(int a) {return binpow(a, mod - 2);}
int fact[N], invfact[N];
void compute() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i)fact[i] = mul(fact[i - 1], i);
    invfact[N - 1] = inv(fact[N - 1]);
    for (int i = N - 2; i >= 0; --i)invfact[i] = mul(invfact[i + 1], i + 1);
}
class Solution {
public:
    int countAnagrams(string s) {
        static bool initialized = false;
        if (!initialized) {
            compute();
            initialized = true;
        }
        int64_t ans = 1;
        string current;
        for (int i = 0; i <= (int)s.size(); ++i) {
            if (i == (int)s.size() || s[i] == ' ') {
                int n = current.size();
                vector<int> freq(26, 0);
                for (char c : current) ++freq[c - 'a'];
                int ways = fact[n];
                for (int j = 0; j < 26; ++j)ways = mul(ways, invfact[freq[j]]);
                ans = (ans * ways) % mod;
                current.clear();
            }
            else current += s[i];
        }
        return int(ans);
    }
};