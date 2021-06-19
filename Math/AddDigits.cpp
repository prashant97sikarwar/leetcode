//Problem link:- https://leetcode.com/problems/add-digits/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int n){
        int res = 0;
        while (n > 0){
            res += n%10;
            n /= 10;
        }
        return res;
    }
    
    int addDigits(int num) {
        while (num / 10 != 0){
            num = helper(num);
        }
        return num;
    }
};