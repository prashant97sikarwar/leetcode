//Problem Link:- https://leetcode.com/problems/nth-magical-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int hcf(int x,int y){
        if (x == 0){
            return y;
        }
        return hcf(y%x,x);
    }
    
    int nthMagicalNumber(int n, int a, int b) {
        int MOD = 1e9 + 7;
        int lcm = a / hcf(a,b) * b;
        long l = 0;
        long r = (long)n*min(a,b);
        while (l < r){
            long mid = l + (r-l)/2;
            if (mid / a + mid / b -mid/lcm < n){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return (int)(l%MOD);
    }
};