//problem Link;- https://leetcode.com/problems/maximum-of-absolute-value-expression/

/* Given two arrays of integers with equal lengths, return the maximum value of:
1. |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
where the maximum is taken over all 0 <= i, j < arr1.length. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        vector<pair<int,int>> path{{1,1},{-1,1},{1,-1},{-1,-1}};
        int ans = 0;
        for(auto check : path){
            int s1 = check.first;
            int s2  =  check.second;
            int mx = INT_MIN;
            int mn = INT_MAX;
            for(int i=0;i<arr1.size();i++){
                mx = max(mx,s1*arr1[i] + s2*arr2[i] + i);
                mn = min(mn,s1*arr1[i] + s2*arr2[i] + i);
            }
            ans = max(ans,mx-mn);
        }
        return ans;
    }
};