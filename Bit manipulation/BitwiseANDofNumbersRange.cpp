//Problem Link:- https://leetcode.com/problems/bitwise-and-of-numbers-range/

/* Given two integers left and right that represent the range [left, right], return the 
bitwise AND of all numbers in this range, inclusive. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long long res = 0;
        for(long long i=0;i<32;i++){
            bool flag = false;
            for(long long j=left;j<=right;j++){
                if ((1 << i) & j)
                    continue;
                else{
                    flag = true;
                    break;
                }
            }
            if (flag == false)
                res |= (1 << i);
        }
        return res;
    }
};

