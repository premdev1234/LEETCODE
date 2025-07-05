
// Custom memory pool for dynamic allocation using a pre-allocated buffer
const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;

void* operator new(size_t size) {
    constexpr std::size_t alignment = alignof(std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;
    char* aligned_ptr = &buffer[buffer_pos + padding];
    buffer_pos += total_size;
    return aligned_ptr;
}

void operator delete(void* ptr, unsigned long) {}
void operator delete(void* ptr) {}
void operator delete[](void* ptr) {}
#define vvc vector<vector<char>>
class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        memset(rowMask, 0, sizeof(rowMask));
        memset(colMask, 0, sizeof(colMask));
        memset(boxMask, 0, sizeof(boxMask));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int boxIndex = (i / 3) * 3 + (j / 3);
                    rowMask[i][num] = colMask[j][num] = boxMask[boxIndex][num] = 1;
                }
            }
        }
        solve(board);
    }

private:
    bitset<9> rowMask[9], colMask[9], boxMask[9];

    bool solve(vector<vector<char>> &board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    int boxIndex = (row / 3) * 3 + (col / 3);
                    for (int num = 0; num < 9; num++) {
                        if (!rowMask[row][num] && !colMask[col][num] && !boxMask[boxIndex][num]) {
                            board[row][col] = num + '1';
                            rowMask[row][num] = colMask[col][num] = boxMask[boxIndex][num] = 1;

                            if (solve(board)) return true;

                            board[row][col] = '.';
                            rowMask[row][num] = colMask[col][num] = boxMask[boxIndex][num] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};