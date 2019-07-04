/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> pos(n);
        vector<vector<string>> result;
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
            if (!flag) {
                continue;
            }
            vector<string> tmp(n, string(n, '.'));
            for (int i = 0; i < n; ++i) {
                tmp[i][pos[i]] = 'Q';
            }
            result.push_back(tmp);
        } while (next_permutation(pos.begin(), pos.end()));
        return result;
    }
};

