class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();

        vector<int> prev(m + 1), curr(m + 1);

        // Base case for the first row (i = 0)
        for (int j = 0; j <= m; ++j) prev[j] = j;

        for (int i = 1; i <= n; ++i) {
            curr[0] = i;  // Base case for current row (j = 0)

            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];  // No operation needed
                } else {
                    curr[j] = 1 + min({prev[j],    // Delete
                                       curr[j - 1], // Insert
                                       prev[j - 1]  // Replace
                    });
                }
            }

            swap(prev, curr);
        }

        return prev[m];
    }
};
