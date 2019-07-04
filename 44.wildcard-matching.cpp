/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */
// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int m = s.size(), n = p.size();
//         vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
//         dp[0][0] = 1;
//         for (size_t i = 1; i <= n; ++i) {
//             dp[0][i] = dp[0][i - 1] && p[i - 1] == '*';
//         }

//         for (size_t i = 1; i <= m; ++i) {
//             for (size_t j = 1; j <= n; ++j) {
//                 if (p[j - 1] == '*') {
//                     dp[i][j] = (dp[i][j - 1] || dp[i - 1][j]);
//                 }
//                 else {
//                     dp[i][j] = (dp[i - 1][j - 1] && (p[j - 1] == '?' || p[j - 1] == s[i - 1]));
//                 }
//             }
//         }
//         return dp[m][n];
//     }
// };


class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        int i = 0, j = 0, asterisk = -1, match;
        while (i < m) {
            if (j < n && p[j] == '*') {
                match = i;
                asterisk = j++;
            }
            else if (j < n && (p[j] == '?' || p[j] == s[i])) {
                ++i;
                ++j;
            }
            else if (asterisk >= 0) {
                i = ++match;
                j = asterisk + 1;
            }
            else {
                return false;
            }
        }
        while (j < n && p[j] == '*') {
            ++j;
        }
        return j == n;
    }
};
