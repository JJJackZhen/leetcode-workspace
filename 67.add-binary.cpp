/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int length = max(a.length(), b.length()) + 1;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i = a.length(); i < length; ++i) {
            a.push_back('0');
        }
        for (int i = b.length(); i < length; ++i) {
            b.push_back('0');
        }
        string result(length, 0);
        bool flag = false;
        for (int i = 0; i < result.size(); ++i) {
            result[i] = a[i] -'0' + b[i] + flag;
            if (result[i] > '1') {
                result[i] -= 2;
                flag = true;
            }
            else {
                flag = false;
            }
        }
        if (*(result.end() - 1) == '0') {
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

