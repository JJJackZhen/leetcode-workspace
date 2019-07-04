/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        s = " " + s + " ";
        reverse(s.begin(), s.end());
        int i = 0;
        while (i < s.size() && s[i] == ' ') {
            ++i;
        }
        if (i == s.size()) {
            return 0;
        }
        int j = i;
        while (s[j] != ' ') {
            ++j;
        }
        return j - i;
    }
};

