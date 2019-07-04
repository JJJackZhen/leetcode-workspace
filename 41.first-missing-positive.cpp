/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) {
            return 1;
        }
        nums.push_back(nums[0]);
        for (auto &num: nums) {
            if (num >= nums.size() || num <= 0) {
                num = 0;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != i && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            }
        }

        for (int i = 1; i < nums.size(); ++i) {
            if (i != nums[i]) {
                return i;
            }
        }

        return nums.size();
    }
};

