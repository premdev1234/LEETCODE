class Solution {
public:

    int maxJumps(vector<int>& a, int d) {
        int n = (int)a.size();
        vector<int> hops(n), indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(),
            [&](int i, int j) {
                return a[i] < a[j];
            });

        int best = 1;
        for (int id = 0; id < n; ++id) {
            int index = indices[id];
            hops[index] = 0;
            for (int j = index - 1;j >= max(0, index - d);--j) {
                if (a[j] >= a[index])break;
                hops[index] = max(hops[index], hops[j] + 1);
            }
            for (int j = index + 1;j <= min(n - 1, index + d);++j) {
                if (a[j] >= a[index])break;
                hops[index] = max(hops[index], hops[j]+1);
            }
            best = max(best, hops[index] + 1);
        }
        return best;
    }
};