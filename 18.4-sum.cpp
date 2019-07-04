/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size(); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int l = j + 1, r = nums.size() - 1;
                if (l >= nums.size() || l >= r) {
                    continue;
                }
                while (l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum < target) {
                        ++l;
                    }
                    else if (sum > target) {
                        --r;
                    }
                    else {
                        result.push_back(vector<int>({nums[i], nums[j], nums[l], nums[r]}));
                        do {
                            ++l;
                        } while (nums[l] == nums[l - 1] && l < r);
                        do {
                            --r;
                        } while (nums[r] == nums[r + 1] && l < r);
                    }
                }
            }
        }
        return result;
    }
};

