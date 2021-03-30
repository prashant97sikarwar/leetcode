//Problem Link:- https://leetcode.com/problems/integer-replacement/

/* Given a positive integer n, you can apply one of the following operations:
1.If n is even, replace n with n / 2.
2.If n is odd, replace n with either n + 1 or n - 1.
Return the minimum number of operations needed for n to become 1. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<long long,int> dp;
    long long helper(long long n){
        if (dp.find(n) != dp.end()){
            return dp[n];
        }
        if (n == 1)
            return 0;
        if (n % 2 == 0){
            dp[n] = 1 + helper(n / 2);
        }
        else{
            dp[n] = 1 + min(helper(n-1), helper(n+1));   
        }
        return dp[n];
    }
    
    int integerReplacement(int n) {
        return helper(n);
    }
};