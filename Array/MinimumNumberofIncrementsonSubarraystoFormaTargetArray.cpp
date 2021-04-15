//Problem Link:- https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/

/* Given an array of positive integers target and an array initial of same size with all zeros.
Return the minimum number of operations to form a target array from initial if you are allowed 
to do the following operation:Choose any subarray from initial and increment each value by one.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res = 0;
        int x= 0;
        for(int cur : target){
            if (cur > x){
                res += (cur - x);
            }
            x = cur;
        }
        return res;
        
    }
};