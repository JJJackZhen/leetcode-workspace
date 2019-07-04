/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
class Solution
{
public:
    double myPow(double x, int n) {
        if (n==0) return 1;
        if (n==1) return x;
        if (n==-1) return 1/x;
        return myPow(x*x,n/2)*(n%2==0?1:n>0?x:1/x);
    }
};


