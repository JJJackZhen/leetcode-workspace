/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */
class Solution {
public:
    int totalNQueens(int n) {
        vector<int> pos(n);
        int result = 0;
        for (int i = 0; i < n; ++i) {
            pos[i] = i;
        }
        do {
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if(abs(i - j) == abs(pos[i] - pos[j])) {
                        flag = false;
                    }
                }
            }
            result += flag;
        } while (next_permutation(pos.begin(), pos.end()));
        return result;
    }
};
