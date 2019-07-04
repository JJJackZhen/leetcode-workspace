/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        if (nums1.size() > nums2.size()) {
            nums1.swap(nums2);
        }

        int l = 0, r = nums1.size(), halfLen = (nums1.size() + nums2.size() + 1) >> 1;

        while (l <= r) {
            int i = (l + r) >> 1, j = halfLen - i;
            if (i < r && nums2[j-1] > nums1[i]) {
                l = i + 1;
            }
            else if (i > l && nums1[i-1] > nums2[j]) {
                r = i - 1;
            }
            else {
                int maxLeft = INT_MIN;
                if (i) {
                    maxLeft = max(maxLeft, nums1[i-1]);
                }
                if (j) {
                    maxLeft = max(maxLeft, nums2[j-1]);
                }
                if((nums1.size() + nums2.size()) & 1) {
                    return maxLeft;
                }

                int minRight = INT_MAX;
                if (i < nums1.size()) {
                    minRight = min(minRight, nums1[i]);
                }
                if (j < nums2.size()) {
                    minRight = min(minRight, nums2[j]);
                }

                return 0.5 * (minRight + maxLeft);
            }
        }
        return 0.0;
    }
};

