class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n); // To store first n super ugly numbers
        ugly[0] = 1;

        int k = primes.size();
        vector<int> idx(k, 0);       // Index for each prime
        vector<long> next(k);        // Next candidate multiple for each prime

        for (int i = 0; i < k; ++i) {
            next[i] = primes[i];     // Initialize with primes
        }

        for (int i = 1; i < n; ++i) {
            long next_ugly = *min_element(next.begin(), next.end());
            ugly[i] = next_ugly;

            for (int j = 0; j < k; ++j) {
                if (next[j] == next_ugly) {
                    idx[j]++; // move pointer forward
                    next[j] = ugly[idx[j]] * (long)primes[j];
                }
            }
        }

        return ugly[n - 1];
    }
};
