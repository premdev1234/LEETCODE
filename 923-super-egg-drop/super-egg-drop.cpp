class Solution
{
public:
    int superEggDrop(int k, int n)
    {
        if (k == 1)
            return n; // linear search

        vector<int> dp(k + 1, 0);
        int moves = 0;

        while (dp[k] < n)
        {
            moves++;
            for (int eggs = k; eggs >= 1; eggs--)
            {
                dp[eggs] = dp[eggs] + dp[eggs - 1] + 1;
            }
        }
        return moves;
    }
};