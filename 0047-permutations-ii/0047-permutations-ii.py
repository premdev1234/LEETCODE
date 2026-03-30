class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        freq = {}
        for num in nums:
            freq[num] = freq.get(num, 0) + 1
        def dfs(path):
            if len(path) == len(nums):
                res.append(path[:])
                return
            for num in freq:
                if freq[num] > 0:
                    path.append(num)
                    freq[num] -= 1
                    dfs(path)
                    path.pop()
                    freq[num] += 1
        dfs([])
        return res