class Solution {
public:
    vector<vector<int>> dp;
    bool dfs(int idx, int balance, string &s) {
        if(balance < 0) return false;
        if(idx == s.size())return balance == 0;
        if(dp[idx][balance] != -1)return dp[idx][balance];
        bool ans = false;
        if(s[idx] == '(')ans = dfs(idx + 1, balance + 1, s);
        else if(s[idx] == ')') ans = dfs(idx + 1, balance - 1, s);
        else ans = dfs(idx + 1, balance + 1, s) || dfs(idx + 1, balance - 1, s) || dfs(idx + 1, balance, s); 
        return dp[idx][balance] = ans;
    }
    bool checkValidString(string s) {
        int n = s.size();
        dp.assign(n + 1, vector<int>(n + 1, -1));
        return dfs(0, 0, s);
    }
};