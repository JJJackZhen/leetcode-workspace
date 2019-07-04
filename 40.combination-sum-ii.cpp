/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfsTree(candidates, 0, target, tmp);
        return result;
    }

private:
    vector<vector<int>> result;
    vector<int> tmp;

    void dfsTree(vector<int>& candidates, int index, int residue, vector<int> &tmp) {
        if (residue == 0) {
            result.push_back(tmp);
            return;
        }
        for (size_t i = index; i < candidates.size(); ++i) {
            while (i > index && i < candidates.size() && candidates[i] == candidates[i - 1]) {
                ++i;
            }
            if (i < candidates.size() && residue >= candidates[i]) {
                tmp.push_back(candidates[i]);
                dfsTree(candidates, i + 1, residue - candidates[i], tmp);
                tmp.pop_back();
            }
        }
    }
};

