/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; 2 * i + 1 < n; ++i) {
            for (int j = 0; 2 * j < n; ++j) {
                int x1 = i, x2 = j, x3 = n - 1 - i, x4 = n - 1 - j;
                int y1 = j, y2 = n - 1 - i, y3 = n - 1 - j, y4 = i;
                int val1 = matrix[x1][y1], val2 = matrix[x2][y2], val3 = matrix[x3][y3], val4 = matrix[x4][y4];
                matrix[x2][y2] = val1, matrix[x3][y3] = val2, matrix[x4][y4] = val3, matrix[x1][y1] = val4;
            }
        }
    }
};

