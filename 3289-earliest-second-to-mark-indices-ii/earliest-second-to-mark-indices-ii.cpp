class Solution {
public:
    bool canMarkAll(int t, vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size();
        vector<int> firstChange(n, -1);

        // Store first occurrence of each index in changeIndices
        for (int i = 0; i <= t; i++) {
            int idx = changeIndices[i] - 1;
            if (firstChange[idx] == -1)
                firstChange[idx] = i;
        }

        long long totalOperations = 0;
        for (int num : nums) totalOperations += num + 1;  // Worst-case operations

        priority_queue<int, vector<int>, greater<int>> pq;
        long long extraOperations = 0;

        // Traverse in reverse order (latest first) to efficiently mark and decrement
        for (int i = t; i >= 0; i--) {
            int idx = changeIndices[i] - 1;
            if (firstChange[idx] != i || nums[idx] == 0) {
                extraOperations++;
                continue;
            }

            pq.push(nums[idx]); // Insert into min heap

            if (extraOperations > 0) {
                extraOperations--;  // Use available "spare operations"
            } else {
                pq.pop();  // Remove smallest value, since we must use decrement operations
                extraOperations++;  // Consider this as an operation used
            }
        }

        // Sum remaining values in priority queue
        long long pqSum = 0;
        while (!pq.empty()) {
            pqSum += pq.top() + 1;
            pq.pop();
        }

        return totalOperations - pqSum <= extraOperations;
    }

    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size(), m = changeIndices.size();
        if (m < n) return -1; // Not enough changes possible

        int left = 0, right = m - 1, answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canMarkAll(mid, nums, changeIndices)) {
                answer = mid;
                right = mid - 1;  // Reduce search space
            } else {
                left = mid + 1;   // Increase search space
            }
        }

        return (answer == -1) ? -1 : answer + 1;
    }
};
