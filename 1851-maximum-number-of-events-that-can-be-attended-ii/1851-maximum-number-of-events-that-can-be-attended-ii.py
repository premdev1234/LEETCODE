class Solution:
    def maxValue(self, events, k):
        events.sort()
        n = len(events)
        starts = [e[0] for e in events]
        nxt = [0] * n
        for i in range(n):
            nxt[i] = bisect_right(starts, events[i][1])
        dp = [[0] * (k + 1) for _ in range(n + 1)]
        for i in range(n - 1, -1, -1):
            for j in range(1, k + 1):
                dp[i][j] = max( dp[i + 1][j], events[i][2] + dp[nxt[i]][j - 1] )
        return dp[0][k]