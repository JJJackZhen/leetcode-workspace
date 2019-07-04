/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */
class Solution {
public:
    bool isPalindrome(int x) {
        string tmp = to_string(x);
        string tmp1 = tmp;
        reverse(tmp.begin(), tmp.end());
        return tmp == tmp1;
    }
};

