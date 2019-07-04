/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> results;
        for (const auto &str: strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            results[tmp].push_back(str);
        }
        vector<vector<string>> ans;
        for (const auto & result: results) {
            ans.push_back(result.second);
        }
        return ans;
    }
};

