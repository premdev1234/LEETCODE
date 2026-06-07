class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        l = min(s + d for s, d in zip(landStartTime, landDuration))
        w = min(s + d for s, d in zip(waterStartTime, waterDuration))
        L = min(
            max(l, s) + d
            for s, d in zip(waterStartTime, waterDuration)
        )
        W = min(
            max(w, s) + d
            for s, d in zip(landStartTime, landDuration)
        )

        return min(L, W)