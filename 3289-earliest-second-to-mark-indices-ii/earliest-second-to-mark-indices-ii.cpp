class Solution {
public:
    bool canMarkAll(int mid, vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size();
        vector<int> firstIndex(n, -1);
        long long totalOperations = 0, extraOperations = 0;

        // Store first occurrence of each index in changeIndices
        for (int i = 0; i <= mid; i++) {
            if (firstIndex[changeIndices[i] - 1] == -1)
                firstIndex[changeIndices[i] - 1] = i;
        }

        // Calculate the worst-case operations needed
        for (long long val : nums) totalOperations += val + 1;

        priority_queue<int, vector<int>, greater<int>> pq; // Min heap for optimal reduction

        // Traverse in reverse order to efficiently mark and decrement
        for (int s = mid; s >= 0; s--) {
            int idx = changeIndices[s] - 1, val = nums[idx];

            if (firstIndex[idx] != s || val == 0) {
                extraOperations++;
                continue;
            }

            pq.push(val);  // Consider this value for operation 3 (direct zeroing)

            if (extraOperations) {
                extraOperations--;  // Use an extra operation if available
            } else {
                pq.pop();  // Remove lowest-priority decrement
                extraOperations++;  // Simulate decrement usage
            }
        }

        long long pqSum = 0;
        while (!pq.empty()) {
            pqSum += pq.top() + 1;
            pq.pop();
        }

        return (totalOperations - pqSum) <= extraOperations;
    }

    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size(), m = changeIndices.size();
        if (m < n) return -1; // Not enough operations

        int left = 0, right = m - 1, answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canMarkAll(mid, nums, changeIndices)) {
                answer = mid;
                right = mid - 1;  // Search for smaller mid
            } else {
                left = mid + 1;   // Increase search space
            }
        }

        return (answer == -1) ? -1 : answer + 1;
    }
};
