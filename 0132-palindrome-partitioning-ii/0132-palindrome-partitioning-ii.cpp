class Solution {
public:
    int minCut(string s) {
        int n = (int)s.size();
        std::vector<std::vector<bool>> palindrome(n, std::vector<bool>(n,false));
        for(int i = n-1; ~i; --i)for(int j = i; j < n; ++j)if(s[i] == s[j] && (j - i <= 2 || palindrome[i+1][j-1]))palindrome[i][j] = true; 
        std::vector<int> dp(n); 
        for(int i = 0; i < n; ++i){
            if(palindrome[0][i]) dp[i] = 0;
            else{
                dp[i] = i;
                for(int j = 1; j <= i; ++j)if(palindrome[j][i])dp[i] = min(dp[i], dp[j-1] + 1);
            }
        }
        return dp[n-1];
    }
};