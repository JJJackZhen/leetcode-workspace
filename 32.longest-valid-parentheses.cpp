/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        for (int flag = 0; flag < 2; ++flag) {
            int countL = 0, countR = 0;
            if (flag) {
                reverse(s.begin(), s.end());
            }
            for (const auto c: s) {
                ++((c == '(' ^ flag) ? countL : countR);
                if (countL == countR) {
                    result = max(result, countR << 1);
                }
                else if (countL < countR) {
                    countL = countR = 0;
                }
            }
        }
        return result;
    }
};

// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         s = '#' + s;
//         if (s.empty()) {
//             return 0;
//         }
//         vector<int> dp(s.size(), 0);
//         for (size_t i = 2; i < s.size(); ++i) {
//             if (s[i] == '(') {
//                 continue;
//             }
//             if (s[i - 1] == '(') {
//                 dp[i] = dp[i - 2] + 2;
//             }
//             if (s[i - 1] == ')' && s[i - dp[i - 1] - 1] == '(') {
//                 dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
//             }
//         }
//         return *max_element(dp.begin(), dp.end());
//     }
// };
