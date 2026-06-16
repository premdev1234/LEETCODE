class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        events.sort()
        starts = [e[0] for e in events]
        n = len(events)
        @lru_cache(None)
        def dfs(i, rem):
            if i == n or rem == 0:
                return 0
            skip = dfs(i + 1, rem)
            nxt = bisect_right(starts, events[i][1])
            take = events[i][2] + dfs(nxt, rem - 1)
            return max(skip, take)
        return dfs(0, k)