//Problem Link:- https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/

#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const unsigned long long mod = 1e9 + 7;
    unsigned long long power(unsigned long long a, unsigned long long b){
        if (b == 0){
            return 1;
        }
        if (b%2 == 0){
            unsigned long long temp = power(a,b/2);
            return (temp * temp)%mod;
        }
        else{
            unsigned long long temp = power(a,b/2);
            temp = (temp * temp)%mod;
            return (temp * (a%mod))%mod;
        }
    }
    
    int minNonZeroProduct(int p) {
        unsigned long long val = (1LL*1 << p) -1;
        return (val%mod * (power(val-1LL*1,val/2)%mod))%mod;
    }
};