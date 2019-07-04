/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */
#pragma GCC optimise ("Ofast")
static auto x = []() {ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c != '.' )  {
                    row[i][c]++;
                    col[j][c]++;
                    blk[i / 3 * 3 + j / 3][c]++;
                }
            }
        }
        dfsTree(board);
    }

private:
    bool dfsTree(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.' )  {
                    for (char c = '1'; c <= '9'; ++c) {
                        if (isValidSudoku(i, j, c)) {
                            board[i][j] = c;
                            row[i][c] += 1;
                            col[j][c]++;
                            blk[i / 3 * 3 + j / 3][c]++;
                            if (dfsTree(board)) {
                                return true;
                            }

                            board[i][j] = '.';
                            row[i][c]--;
                            col[j][c]--;
                            blk[i / 3 * 3 + j / 3][c]--;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(int i, int j, char c) {
        return (c != '.') && (row[i][c] == 0) && (col[j][c] == 0) && (blk[i / 3 * 3 + j / 3][c] == 0);
    }
    map<char, int> row[9], col[9], blk[9];
};

