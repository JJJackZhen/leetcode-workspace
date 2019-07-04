/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
            if (residue >= candidates[i]) {
                tmp.push_back(candidates[i]);
                dfsTree(candidates, i, residue - candidates[i], tmp);
                tmp.pop_back();
            }
        }
    }
};

