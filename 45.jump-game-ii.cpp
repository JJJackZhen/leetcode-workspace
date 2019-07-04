/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> jumpsHeight = {0, nums[0]};
        for (int i = 2; i <= nums.size(); ++i) {
            int tmp = 0;
            for (int j = jumpsHeight[i - 2] + 1; j <= min(jumpsHeight[i - 1], static_cast<int>(nums.size()) - 1); ++j) {
                tmp = max(tmp, j + nums[j]);
            }
            jumpsHeight.push_back(tmp);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (jumpsHeight[i] + 1 >= nums.size()) {
                return i;
            }
        }
        return 0;
    }
};

