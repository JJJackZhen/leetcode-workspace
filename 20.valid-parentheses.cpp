/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c: s) {
            switch (c)
            {
            case '(':
            case '{':
            case '[':
                stk.push(c);
                break;
            case ')':
                if (!stk.empty() && stk.top() == '(') {
                    stk.pop();
                }
                else {
                    return false;
                }
                break;
            case '}':
                if (!stk.empty() && stk.top() == '{') {
                    stk.pop();
                }
                else {
                    return false;
                }
                break;
            case ']':
                if (!stk.empty() && stk.top() == '[') {
                    stk.pop();
                }
                else {
                    return false;
                }
                break;
            }
        }
        return stk.empty();
    }
};

