class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> pl(n, -1), nl(n, n), pg(n, -1), ng(n, n);
        stack<int> mono;

        // Next Less
        while (!mono.empty()) mono.pop();
        for (int i = 0; i < n; i++) {
            while (!mono.empty() && nums[mono.top()] > nums[i]) {
                nl[mono.top()] = i;
                mono.pop();
            }
            mono.push(i);
        }

        // Previous Less
        while (!mono.empty()) mono.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!mono.empty() && nums[mono.top()] >= nums[i]) {
                pl[mono.top()] = i;
                mono.pop();
            }
            mono.push(i);
        }

        // Next Greater
        while (!mono.empty()) mono.pop();
        for (int i = 0; i < n; i++) {
            while (!mono.empty() && nums[mono.top()] < nums[i]) {
                ng[mono.top()] = i;
                mono.pop();
            }
            mono.push(i);
        }

        // Previous Greater
        while (!mono.empty()) mono.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!mono.empty() && nums[mono.top()] <= nums[i]) {
                pg[mono.top()] = i;
                mono.pop();
            }
            mono.push(i);
        }

        // Contribution
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long max_contrib = 1LL * nums[i] * (i - pg[i]) * (ng[i] - i);
            long long min_contrib = 1LL * nums[i] * (i - pl[i]) * (nl[i] - i);
            sum += max_contrib - min_contrib;
        }

        return sum;
    }
};
