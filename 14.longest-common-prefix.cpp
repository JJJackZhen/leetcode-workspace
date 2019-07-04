/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strings) {
        if (strings.empty()) {
            return string();
        }
        string tmp = strings[0];
        for (int i = tmp.size(); i >= 0; --i) {
            string prefix = tmp.substr(0, i);
            bool flag = true;
            for (const auto &str: strings) {
                if (str.find(prefix) != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return prefix;
            }
        }
        return "";
    }
};

