//Problem Link:- https://leetcode.com/problems/count-good-numbers/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long mod = 1e9 + 7;
    long long pow(long long a,long long b){
        long long res = 1;
        while (b > 0){
            if (b&1){
                res *= a%mod;
                b--;
                res %= mod;
            }
            else{
                a *= a%mod;
                b /= 2;
                a%= mod;      
            }
        }
        return res;
    }
    
    int countGoodNumbers(long long n) {
        if (n == 1){
            return 5;
        }
        long long even;
        long long odd = n/2;
        if (n % 2 == 0){
            even = n/ 2;
        }
        else{
            even = (n-1)/2 + 1;
        }
        
        long long res = (pow(5,even)%mod * pow(4,odd)%mod)%mod;
        return int(res%mod);
    }
};