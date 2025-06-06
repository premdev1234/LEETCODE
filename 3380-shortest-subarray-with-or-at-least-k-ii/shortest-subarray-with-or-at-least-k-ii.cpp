class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int cnt[32] = {};
        auto add = [&](int x) {
            for (int i = 0; i < 32; ++i)
                if ((x >> i) & 1) cnt[i]++;
        };
        auto remove = [&](int x) {
            for (int i = 0; i < 32; ++i)
                if ((x >> i) & 1) cnt[i]--;
        };
        auto current_OR = [&]() {
            int res = 0;
            for (int i = 0; i < 32; ++i)
                if (cnt[i]) res |= (1 << i);
            return res;
        };

        int n = nums.size();
        int left = 0, ans = INT_MAX;

        for (int right = 0; right < n; ++right) {
            add(nums[right]);
            while (left <= right && current_OR() >= k) {
                ans = min(ans, right - left + 1);
                remove(nums[left++]);
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};
