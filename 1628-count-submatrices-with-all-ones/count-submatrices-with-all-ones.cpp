class Solution {
public:
    int numSubmat(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();

        // Step 1: Compute heights of consecutive ones column-wise
        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 1)
                    matrix[i][j] += matrix[i - 1][j];
            }
        }

        int total = 0;

        // Step 2: For each row, use monotonic stack to count submatrices ending at each column
        for (int i = 0; i < rows; ++i) {
            stack<int> stk;
            vector<int> count(cols, 0);

            for (int j = 0; j < cols; ++j) {
                while (!stk.empty() && matrix[i][stk.top()] >= matrix[i][j]) {
                    stk.pop();
                }

                if (stk.empty()) {
                    count[j] = matrix[i][j] * (j + 1);
                } else {
                    int prev = stk.top();
                    count[j] = count[prev] + matrix[i][j] * (j - prev);
                }

                stk.push(j);
            }

            for (const int& cnt : count) {
                total += cnt;
            }
        }

        return total;
    }
};
