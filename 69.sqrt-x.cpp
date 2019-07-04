/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */
class Solution {
public:
    int mySqrt(int x) {
        if (!x) {
            return 0;
        }
        long long l = 1, r = x;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (mid * mid >= x) {
                r = mid;
            }
            else {
                l = 
            }
        }
    }
};

