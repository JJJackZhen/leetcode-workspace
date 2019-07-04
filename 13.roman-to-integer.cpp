/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */
class Solution {
public:
    int romanToInt(string s) {
        string table[4][10] = {
                                {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                                {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                                {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                                {"", "M", "MM", "MMM"}
                            };
        int base[4] = {1, 10,  100, 1000};
        int result = 0;
        for (int i = 3; i >= 0 ; --i) {
            for (int j = 9; j >= 0; --j) {
                string tmp = table[i][j];
                if (tmp != "" && s.find(tmp) == 0) {
                    result += base[i] * j;
                    s = s.substr(tmp.length(), s.length() - tmp.length());
                }
            }
        }
        return result;
    }
};

