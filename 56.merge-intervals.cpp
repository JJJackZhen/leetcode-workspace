/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); ++i) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            while (i + 1 < intervals.size() && end >= intervals[i + 1][0]) {
                ++i;
                end = max(end, intervals[i][1]);
            }
            result.push_back(vector<int>({start, end}));
        }
        return result;
    }    
};

