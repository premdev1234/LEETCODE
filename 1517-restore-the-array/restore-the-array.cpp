class Solution {
public:
    int numberOfArrays(string s, int k) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        string k_str = to_string(k);
        int len_k = k_str.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            long long count = 0;
            int max_len = min(len_k, i);
            
            for (int l = 1; l <= max_len; ++l) {
                int j = i - l;
                if (j < 0) break;
                if (s[j] == '0') continue;

                if (l < len_k) {
                    count = (count + dp[j]) % MOD;
                } 
                else {
                    bool valid = true;
                    for (int m = 0; m < l; ++m) {
                        if (s[j + m] > k_str[m]) {
                            valid = false;
                            break;
                        }
                        else if (s[j + m] < k_str[m]) break;
                    }
                    if (valid) count = (count + dp[j]) % MOD;
                }
            }
            dp[i] = count;
        }
        return dp[n];
    }
};