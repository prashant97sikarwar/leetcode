//Problem Link:- https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool prime(int n){
        if (n <= 1){
            return false;
        }
        for(int i=2;i*i<=n;i++){
            if (n%i == 0){
                return false;
            }
        }
        return true;
    }
    
    bool check(int n){
        int temp = n;
        int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        if (prime(count)){
            return true;
        }
        return false;
    }
    
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for(int i=left;i<=right;i++){
            if (check(i)){
                res++;
            }
        }
        return res;
    }
};