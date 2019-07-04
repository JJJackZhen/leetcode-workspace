/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        vector<int> maxL(height.size()), maxR(height.size());
        int maxTmpL = 0, maxTmpR = 0;
        for (int i = 0; i < height.size(); ++i) {
            maxL[i] = maxTmpL;
            maxTmpL = max(maxTmpL, height[i]);
        }
        for (int i = height.size() - 1; i >= 0; --i) {
            maxR[i] = maxTmpR;
            maxTmpR = max(maxTmpR, height[i]);
        }

        for (int i = 0; i < height.size(); ++i) {
            int tmp = min(maxL[i], maxR[i])  - height[i];
            result += tmp > 0 ? tmp : 0;
        }
        return result;
    }
};

