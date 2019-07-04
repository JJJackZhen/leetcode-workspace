/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> jumpsHeight = {0, nums[0]};
        for (int i = 2; i <= nums.size(); ++i) {
            int tmp = 0;
            for (int j = jumpsHeight[i - 2] + 1; j <= min(jumpsHeight[i - 1], static_cast<int>(nums.size()) - 1); ++j) {
                tmp = max(tmp, j + nums[j]);
            }
            if (tmp >= nums.size() - 1) {
                return true;
            }
            if (tmp <= jumpsHeight[i - 1]) {
                return false;
            }
            jumpsHeight.push_back(tmp);
        }
        return true;
    }
};

