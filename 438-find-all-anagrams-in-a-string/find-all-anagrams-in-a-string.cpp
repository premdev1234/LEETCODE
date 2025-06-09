class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), m = p.length();
        if (m > n) return {};

        vector<int> a(26, 0), b(26, 0), res;

        // Build frequency for p
        for (char c : p) a[c - 'a']++;

        // Build frequency for first window in s
        for (int i = 0; i < m; ++i) b[s[i] - 'a']++;

        // Compare first window
        if (a == b) res.push_back(0);

        // Slide the window
        for (int i = m; i < n; ++i) {
            b[s[i] - 'a']++;          // add rightmost char
            b[s[i - m] - 'a']--;      // remove leftmost char
            if (a == b) res.push_back(i - m + 1);
        }

        return move(res);
    }
};
