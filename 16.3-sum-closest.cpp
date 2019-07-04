/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = INT_MAX >> 1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int tmp = nums[i] + nums[l] + nums[r];
                if (tmp == target) {
                    return result = target;
                }
                else if (tmp > target) {
                    if (tmp - target < abs(result - target)) {
                        result = tmp;
                    }
                    --r;
                }
                else {
                    if (target - tmp < abs(result - target)) {
                        result = tmp;
                    }
                    ++l;
                }
            }
        }
        return result;
    }

};

