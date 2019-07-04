/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char, int> row[9], col[9], blk[9];
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c != '.' && (row[i][c]++ || col[j][c]++ || blk[i / 3 * 3 + j / 3][c]++)) {
                    return false;
                }
            }
        }
        return true;
    }
};

