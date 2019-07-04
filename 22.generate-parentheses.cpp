/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
#pragma GCC optimise ("Ofast")
static auto x = []() {ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        generate(n, n, "");
        return result;
    }

private:
    vector<string> result;
    void generate(int left, int right, string tmp) {
        if (left) {
            generate(left - 1, right, tmp + "(");
        }
        if (right && left < right) {
            generate(left, right - 1, tmp + ")");
        }
        if (!left && !right) {
            result.push_back(tmp);
        }
    }
};

