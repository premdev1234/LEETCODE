class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        unordered_map<long long, int> mp;

        for (auto &c : coordinates) {
            int x = c[0], y = c[1];

            for (int dx = -1; dx <= 0; ++dx) {
                for (int dy = -1; dy <= 0; ++dy) {
                    int nx = x + dx, ny = y + dy;

                    if (0 <= nx && nx < m - 1 && 0 <= ny && ny < n - 1) {
                        long long key = (long long)nx * n + ny;
                        mp[key]++;
                    }
                }
            }
        }

        vector<long long> res(5, 0);

        for (auto &[_, cnt] : mp) {
            res[cnt]++;
        }

        long long total = (long long)(m - 1) * (n - 1);
        res[0] = total - (res[1] + res[2] + res[3] + res[4]);

        return res;
    }
};