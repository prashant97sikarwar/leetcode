//Problem Link:- https://leetcode.com/problems/permutation-sequence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<int> factorial(int n){
        vector<int> fact(n+1,0);
        fact[0] = 1;
        fact[1] = 1;
        for(int i=2;i<=n;i++){
            fact[i] = i*fact[i-1];
        }
        return fact;
    }
    
    string getPermutation(int N, int K) {
        vector<int> fact = factorial(N);
        int n = N-1;
        int k = K-1;
        vector<int> nums(N);
        for(int i=0;i<N;i++){
            nums[i] = i+1;
        }
        
        string ans = "";
        while (n>=0){
            int nt = k / fact[n];
            int kt = k % fact[n];
            ans += (nums[nt] + '0');
            
            auto it = nums.begin();
            nums.erase(it+nt);
            n--;
            k = kt;
        }
        return ans;
    }
};