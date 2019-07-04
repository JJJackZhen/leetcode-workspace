/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        init(s);
        return Manacher(s);
    }

private:
    void init(string &s) {
        string str = "$#";
        for (const auto &c: s) {
            str.push_back(c);
            str.push_back('#');
        }
        s = str + "@";
    }

    string Manacher(string s) {
        vector<int> rl(s.size());
        int mr = -1, pos;

        int max_length = -1, max_pos;
        for (int i = 1; i < s.size() - 1; ++i) {
            if (mr <= i) {
                rl[i] = 1;
            }
            else {
                rl[i] = min(mr - i + 1, rl[pos * 2 - i]);
            }
            
            while (i - rl[i] >= 0 && i + rl[i] < s.size() && s[i - rl[i]] == s[i + rl[i]]) {
                rl[i]++;
            }

            if (rl[i] + i >= mr) {
                mr = rl[i] + i - 1;
                pos = i;
                if (rl[i] > max_length) {
                    max_length = rl[i];
                    max_pos = i;
                }
            }
        }

        s = s.substr(max_pos - max_length + 1, max_length * 2 - 1);
        string ret;
        for (int i = 1; i <= s.size(); i += 2) {
            ret.push_back(s[i]);
        }
        return ret;
    }
};

