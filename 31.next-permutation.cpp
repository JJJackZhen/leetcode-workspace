/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        int j = nums.size() - 2;
        while (j >= 0 && nums[j] >= nums[j + 1]) {
            --j;
        }
        if (j == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int i = nums.size() - 1;
        while(nums[i] <= nums[j]) {
            --i;
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + j + 1, nums.end());
    }
};
