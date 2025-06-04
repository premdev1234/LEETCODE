class Solution {
public:
    int findSubstringInWraproundString(string s) {
        if (s.empty()) return 0;

        int dp[26] = {0};  // Initialize all to 0
        int k = 0;

        for (int i = 0; i < (int)s.size(); ++i) {
            if (i > 0 && ((s[i] - s[i - 1] + 26) % 26 == 1))k++;
            else k = 1;
            int index = s[i] - 'a';
            if (dp[index] < k) dp[index] = k;
        }

        int result = 0;
        for (int i = 0; i < 26; ++i) result += dp[i];

        return result;
    }
};
