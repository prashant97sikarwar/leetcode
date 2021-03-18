//Problem link:- https://leetcode.com/problems/numbers-with-same-consecutive-differences/

/* Return all non-negative integers of length n such that the absolute difference between 
every two consecutive digits is k.Note that every number in the answer must not have leading 
zeros. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitCount(int num){
        int cnt = 0;
        while (num > 0){
            cnt++;
            num /= 10;
        }
        return cnt;
    }
    
    void helper(vector<int>& result,int n,int k,int curr){
        if (digitCount(curr) == n){
            result.push_back(curr);
            return;
        }
        for(int i=0;i<=9;i++){
            if (curr == 0 && i == 0)
                continue;
            if (curr == 0 && i != 0){
                curr = 10*curr + i;
                helper(result,n,k,curr);
                curr /= 10;
            }
            if (curr > 0){
                int prev = curr % 10;
                if (abs(prev - i) == k){
                    curr = 10*curr + i;
                    helper(result,n,k,curr);
                    curr /= 10;
                }
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        helper(result,n,k,0);
        return result;
    }
};