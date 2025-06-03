#define ll long long
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define forn(n) for(int i = 0; i < (n); ++i)
#define rfor(i,a,b) for(int i = (a); i >= (b); --i)
class Solution {
public:
    int lastStoneWeightII(vi& stones) {
        const int MAX_SUM = 1500; // Max possible sum of stone weights
        bitset<MAX_SUM + 1> dp;
        dp[0] = 1;

        int totalSum = accumulate(all(stones), 0);

        for (int weight : stones) {
            rfor(i, min(MAX_SUM, totalSum), weight) {
                dp[i] = dp[i] | dp[i - weight];
            }
        }

        // Find the subset sum closest to totalSum / 2
        for (int i = totalSum / 2; i >= 0; --i) {
            if (dp[i]) {
                return totalSum - 2 * i;
            }
        }

        return 0;
    }
};