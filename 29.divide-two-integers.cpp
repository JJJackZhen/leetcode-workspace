/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!dividend) {
            return 0;
        }
        if (!divisor) {
            return INT_MAX;
        }
        long long result = exp(log(fabs(dividend)) - log(fabs(divisor)));
        if ((dividend < 0)^(divisor < 0)) {
            result = -result;
        }
        result = min(result, static_cast<long long>(INT_MAX));
        return result;
    }
};

