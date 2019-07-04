/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
#include <string>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        int indicator = 1;

        int i = str.find_first_not_of(' ');
        if (i < str.length() && (str[i] == '-' || str[i] == '+')) {
            indicator = (str[i++] == '-')? -1: 1;
        }
        while(i < str.length() && str[i] <= '9' && str[i] >= '0') {
            result = result * 10 + str[i++] - '0';
            if (result * indicator <= INT_MIN) {
                return INT_MIN;
            }
            if (result * indicator >= INT_MAX) {
                return INT_MAX;
            }
        }
        return result * indicator;
        
    }
};

