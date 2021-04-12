//Problem Link:- https://leetcode.com/problems/sign-of-the-product-of-an-array/

/*There is a function signFunc(x) that returns:
1. 1 if x is positive.
2. -1 if x is negative.
3. 0 if x is equal to 0.
You are given an integer array nums. Let product be the product of all values in the array nums.
Return signFunc(product). */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        bool flag = false;
        for(int i=0;i<nums.size();i++){
            if (nums[i] < 0){
                neg++;
            }
            else if (nums[i] == 0){
                flag = true;
            }
        }
        if (flag == true){
            return 0;
        }
        if (neg % 2 == 1){
            return -1;
        }
        return 1;
    }
};