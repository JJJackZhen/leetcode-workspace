/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        do {
            result.push_back(nums);
        } while (nextPermutation(nums));
        return result;
    }

private:
    bool nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) {
            return false;
        }
        int j = nums.size() - 2;
        while (j >= 0 && nums[j] >= nums[j + 1]) {
            --j;
        }
        if (j == -1) {
            reverse(nums.begin(), nums.end());
            return false;
        }
        int i = nums.size() - 1;
        while(nums[i] <= nums[j]) {
            --i;
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + j + 1, nums.end());
        return true;
    }
};