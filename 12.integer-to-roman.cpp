/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */
class Solution {
public:
    string intToRoman(int num) {
        string table[4][10] = {
                                {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                                {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                                {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                                {"", "M", "MM", "MMM"}
                            };
        
        string result;

        int flag = 0;
        while (num) {
            result = table[flag++][num%10] + result;
            num /= 10;
        }

        return result;
    }
};

