class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n, 0), lens(n, 0);

        // Step 1: Build bitmask and length array
        for (int i = 0; i < n; ++i) {
            int bitmask = 0;
            for (char c : words[i]) {
                bitmask |= (1 << (c - 'a'));
            }
            mask[i] = bitmask;               // ✅ Store after full word processed
            lens[i] = words[i].length();     // ✅ Also outside the inner loop
        }

        // Step 2: Compare all pairs using bitwise AND
        int maxProd = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((mask[i] & mask[j]) == 0) { // ✅ No common letters
                    maxProd = max(maxProd, lens[i] * lens[j]);
                }
            }
        }

        return maxProd;
    }
};
