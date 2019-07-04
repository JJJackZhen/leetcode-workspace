/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        intervals.push_back(newInterval);
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

