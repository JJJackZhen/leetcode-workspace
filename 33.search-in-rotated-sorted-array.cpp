/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < nums[0]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        if (nums[0] <= target) {
            int ind = lower_bound(nums.begin(), nums.begin() + l, target) - nums.begin();
            return (ind < nums.size() && nums[ind] == target) ? ind : -1;
        }
        else {
            int ind = lower_bound(nums.begin() + l, nums.end(), target) - nums.begin();
            return (ind < nums.size() && nums[ind] == target) ? ind : -1;
        }
    }
};

