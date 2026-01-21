class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy = 10**18
        ans = 0
        for x in prices:
            buy = min(buy, x)
            ans = max(ans, x - buy)
        return ans
