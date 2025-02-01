class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int mod = 1000000007;
        int n = instructions.size();
        int maxVal = 100001;
        vector<int> fenw(maxVal + 1, 0);
        auto update = [&](int index, int val) {
            for(; index <= maxVal; index += index & -index)
                fenw[index] += val;
        };
        auto query = [&](int index) -> int {
            int res = 0;
            for(; index > 0; index -= index & -index)
                res += fenw[index];
            return res;
        };
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int num = instructions[i];
            int less = query(num - 1);
            int greater = i - query(num);
            ans = (ans + min(less, greater)) % mod;
            update(num, 1);
        }
        return ans;
    }
};
