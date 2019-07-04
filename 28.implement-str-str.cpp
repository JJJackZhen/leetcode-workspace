/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */
#pragma GCC optimise ("Ofast")
static auto x = []() {ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        vector<int> Next(needle.size() + 1, 0);
        Next[0] = -1;
        int i = 0, j = -1;
        while (i < needle.size()) {
            while( j != -1 && needle[i] != needle[j]) {
                j = Next[j];
            }
            Next[++i] = ++j;
        }
        i = j = 0;
        while (i < haystack.size() && j < needle.size()) {
            while (j != -1 && needle[j] != haystack[i]) {
                j = Next[j];
            }
            ++i; ++j;
            if (j >= needle.size()) {
                return i - needle.size();
            }
        }
        return -1;
    }
};
