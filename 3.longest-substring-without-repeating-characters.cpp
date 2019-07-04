/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> index(256, -1);
        int ans = !!s.length();
        int last_index = -1;
        for (int i = 0; i < s.length(); ++i) {
            if (index[s[i]] > last_index) {
                last_index = index[s[i]];
            }
            ans = max(ans, i - last_index);
            index[s[i]] = i;
        }
        return ans;
    }
};

