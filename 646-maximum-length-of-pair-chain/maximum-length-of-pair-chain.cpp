class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
            return a[1] < b[1]; // Sort by end time
        });

        int last_end = INT_MIN, chain_len = 0;
        for (auto &p : pairs) {
            if (p[0] > last_end) {
                ++chain_len;
                last_end = p[1];
            }
        }

        return chain_len;
    }
};
