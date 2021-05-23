//Problem Link:- https://leetcode.com/problems/power-of-two/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0){
            return false;
        }
        if (n == 1 || n == 2){
            return true;
        }
        if (n == INT_MIN){
            return false;
        }
        if (n & (n-1)){
            return false;
        }
        return true;
    }
};