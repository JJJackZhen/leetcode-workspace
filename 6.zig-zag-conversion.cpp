/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        string result;
        int cycle = numRows * 2 - 2;
        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < s.length(); j+= cycle) {
                result.push_back(s[j]);
                int second = j + cycle - i - i;
                if (i && i != numRows - 1 && second < s.length()) {
                    result.push_back(s[second]);
                }
            }
        }
        return result;
    }
};

