/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        return isMatch(0, 0);
    }

private:
    bool isMatch(size_t ind1, size_t ind2) {
        if (ind1 == s.length() && ind2 == p.length()) {
            return true;
        }

        if (ind2 + 1 < p.length() && p[ind2 + 1] == '*') {
            for (size_t i = 0; ind1 + i <= s.length(); ++i) {
                if (i == 0 || singleCharacterIsMatch(ind1 + i - 1, ind2)) {
                    if (isMatch(ind1 + i, ind2 + 2)) {
                        return true;
                    }
                }
                else {
                    break;
                }
            }
        }
        return singleCharacterIsMatch(ind1, ind2) && isMatch(ind1 + 1, ind2 + 1);
    }

    bool singleCharacterIsMatch(size_t ind1, size_t ind2) {
        return ind1 < s.length() && ind2 < p.length() && (p[ind2] == '.' || s[ind1] == p[ind2]);
    }

    string s, p;
};

