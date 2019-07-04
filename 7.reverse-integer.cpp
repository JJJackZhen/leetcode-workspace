/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */
class Solution {
public:
    int reverse(int x) {
        long long x_temp = x;
        long long result;
        if (x_temp >= 0) {
            string tmp = to_string(x_temp);
            std::reverse(tmp.begin(), tmp.end());
            result = stoll(tmp);
        }
        else {
            string tmp = to_string(-x_temp);
            std::reverse(tmp.begin(), tmp.end());
            result = -stoll(tmp);
        }
        if (result >= INT_MIN && result <= INT_MAX) {
            return static_cast<int>(result);
        }
        else {
            return 0;
        }
    }
};

