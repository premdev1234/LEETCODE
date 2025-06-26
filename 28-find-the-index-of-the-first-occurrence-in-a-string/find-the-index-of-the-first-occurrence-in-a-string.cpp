class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m > n) return -1;
        int b = 256, md = 1019;

        // Compute the hash of the needle
        int needle_hash = 0;
        for (int i = 0; i < m; i++) {
            needle_hash = (needle_hash * b + needle[i]) % md;
        }

        // Compute the hash of the first substring of haystack of length m
        int haystack_hash = 0;
        for (int i = 0; i < m; i++) {
            haystack_hash = (haystack_hash * b + haystack[i]) % md;
        }

        // Rolling hash: Compare the hash values and slide over the haystack
        int base_m = 1; // base^m % mod (for removing the first character)
        for (int i = 0; i < m; i++) {
            base_m = (base_m * b) % md;
        }

        // Slide the window over haystack
        for (int i = 0; i <= n - m; i++) {
            if (haystack_hash == needle_hash) {
                // If hashes match, compare the substrings to avoid collisions
                if (haystack.substr(i, m) == needle) return i;
            }

            // Update hash for the next window
            if (i < n - m) {
                haystack_hash = (haystack_hash * b - haystack[i] * base_m + haystack[i + m]) % md;
                if (haystack_hash < 0) haystack_hash += md;
            }
        }

        return -1;
    }
};
