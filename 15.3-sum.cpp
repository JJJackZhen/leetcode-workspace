/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> result;
        map<int, int> mp;
        for (auto num: nums) {
            if (mp.count(num)) {
                mp[num]++;
            }
            else {
                mp[num] = 1;
            }
        }
        nums.clear();
        for (auto m: mp) {
            for (int i = 0; i < min(m.second, 3); ++i) {
                nums.push_back(m.first);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            for(int j = i + 1; j < nums.size(); ++j) {
                int c = - (nums[i] + nums[j]);
                auto p = lower_bound(nums.begin() + j + 1, nums.end(), c);
                if (p != nums.end() && *p == c) {
                    result.insert(vector<int>({nums[i], nums[j], c}));
                }
            }
        }
        return vector<vector<int>>(result.begin(), result.end());
    }
};

