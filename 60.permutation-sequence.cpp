/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        string str;
        for (int i = 1; i <= n; ++i) {
            str.push_back(i + '0');
        }
        vector<int> pTable(10, 1);
        for(int i = 1; i <= 9; i++){
            pTable[i] = i * pTable[i - 1];
        }
        string result;
        while (n) {
            int tmp = (k - 1) / pTable[n - 1];
            result += str[tmp];
            str.erase(str.begin() + tmp);
            k = k - tmp * pTable[n - 1];
            --n;
        }
        return result;
    }
};

