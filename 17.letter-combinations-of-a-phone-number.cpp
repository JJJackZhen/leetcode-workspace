/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return vector<string>();
        }
        this -> digits =  digits;
        dfs(0);
        return result;
    }
private:
    void dfs(size_t index) {
        if (index == digits.length()) {
            result.push_back(tmp);
            return;
        }
        for (auto c: tables[digits[index] - '2']) {
            tmp.push_back(c);
            dfs(index + 1);
            tmp.pop_back();
        }
    }

    vector<string> result;
    string tmp, digits;
    vector<string> tables = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};

