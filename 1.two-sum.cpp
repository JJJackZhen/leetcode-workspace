//easy binary search
/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

class Solution {
public:
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     for (size_t i = 0; i < nums.size(); ++i) {
    //         for (size_t j = i + 1; j < nums.size(); ++j) {
    //             if (nums[i] + nums[j] == target) {
    //                 return vector<int>({int(i), int(j)});
    //             }
    //         }
    //     }
    //     return vector<int>();
    // }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> nums_with_index;
        for (int i = 0; i < nums.size(); ++i) {
            nums_with_index.push_back(make_pair(nums[i], i));
        }
        sort(nums_with_index.begin(), nums_with_index.end(), [](pair<int, int> a, pair<int, int> b){return a.first < b.first;});
        for (int i = 0; i< nums.size(); ++i) {
            nums[i] = nums_with_index[i].first;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int residue = target - nums[i];
            auto p = lower_bound(nums.begin() + i + 1, nums.end(), residue);
            if (p != nums.end() && *p == residue) {
                int j = p - nums.begin();
                return vector<int>({nums_with_index[i].second, nums_with_index[j].second});
            }
        }

        return vector<int>();
    }
};

