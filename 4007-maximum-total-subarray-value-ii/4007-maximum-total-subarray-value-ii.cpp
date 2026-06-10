class Solution {
public:
    struct Node {
        long long val;
        int l, r;
        bool operator<(const Node& other) const {
            return val < other.val;
        }
    };
    vector<vector<int>> stMax, stMin;
    vector<int> lg;
    void buildSparse(vector<int>& nums) {
        int n = nums.size();
        lg.resize(n + 1);
        lg[1] = 0;
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }
        int K = lg[n] + 1;
        stMax.assign(K, vector<int>(n));
        stMin.assign(K, vector<int>(n));
        for (int i = 0; i < n; i++) {
            stMax[0][i] = nums[i];
            stMin[0][i] = nums[i];
        }
        for (int k = 1; k < K; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                stMax[k][i] = max(stMax[k - 1][i], stMax[k - 1][i + (1 << (k - 1))]);
                stMin[k][i] = min(stMin[k - 1][i], stMin[k - 1][i + (1 << (k - 1))]);
            }
        }
    }
    int queryMax(int l, int r) {
        int len = r - l + 1;
        int k = lg[len];
        return max( stMax[k][l], stMax[k][r - (1 << k) + 1]);
    }
    int queryMin(int l, int r) {
        int len = r - l + 1;
        int k = lg[len];
        return min( stMin[k][l], stMin[k][r - (1 << k) + 1] );
    }
    long long value(int l, int r) {
        return 1LL * queryMax(l, r) - queryMin(l, r);
    }
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        buildSparse(nums);
        priority_queue<Node> pq;
        for (int l = 0; l < n; l++) {
            pq.push({ value(l, n - 1), l, n - 1 });
        }
        long long ans = 0;
        while (k--) {
            auto cur = pq.top();
            pq.pop();
            ans += cur.val;
            if (cur.r > cur.l) {
                int nr = cur.r - 1;
                pq.push({ value(cur.l, nr), cur.l, nr });
            }
        }
        return ans;
    }
};