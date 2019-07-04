/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long result = INT_MIN, tmp = INT_MIN;
        for (const auto t_num: nums) {
            long long num = t_num;
            tmp = max(tmp + num, num);
            result = max(result, tmp);
        }
        return result;
    }
};

