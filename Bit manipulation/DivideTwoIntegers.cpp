//Problem Link:- https://leetcode.com/problems/divide-two-integers/

/*Given two integers dividend and divisor, divide two integers without using multiplication, 
division, and mod operator.Return the quotient after dividing dividend by divisor.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int ans = 0;
        if (divisor == INT_MIN)
            if (dividend == divisor) return 1;
            else return 0;
        if (dividend == INT_MIN)
            if (divisor == 1) return INT_MIN;
            else if (divisor == -1) return INT_MAX;
            else dividend += abs(divisor), ans++;
        
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        
        dividend = abs(dividend), divisor = abs(divisor);
        while(dividend >= divisor) { 
            int t=1; // multiplier by default 1 since (dividend >= divisor)
            int curr_dvs=divisor;
            int curr_dvd=dividend >> 1;
            
            while (curr_dvd >= divisor){
                curr_dvs = curr_dvs << 1;
                t = t << 1;
                curr_dvd = curr_dvd>>1;
            }

            dividend -= curr_dvs;
            ans += t;
        }
        return sign > 0 ? ans : -ans;
    }
};