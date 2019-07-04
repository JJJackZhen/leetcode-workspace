/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int i = 0, j = height.size() - 1;

        while (i < j) {
            int h = min(height[i], height[j]);
            result = max(result, h * (j - i));
            while(i < j && height[i] <= h) {
                ++i;
            }
            while(i < j && height[j] <= h) {
                --j;
            }
        }
        return result;
    }
};

