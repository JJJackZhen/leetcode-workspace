/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size();
        while (--index >= 0) {
            if (digits[index] != 9) {
                break;
            }
        }
        if (index == -1) {
            vector<int> result(digits.size() + 1);
            result[0] = 1;
            return result;
        }
        else {
            ++digits[index++];
            while (index < digits.size()) {
                digits[index++] = 0;
            }
            return digits;
        }
    }
};

