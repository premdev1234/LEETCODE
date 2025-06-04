class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;

        int prev2 = 1; // dp[0]: empty string
        int prev1 = 1; // dp[1]: first char decoded
        int curr = 0;

        for (int i = 1; i < n; ++i) {
            curr = 0;

            // Check if single-digit decoding is valid
            if (s[i] != '0') {
                curr += prev1;
            }

            // Check if two-digit decoding is valid
            int twoDigit = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                curr += prev2;
            }

            // Shift for next iteration
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
