//Problem Link:- https://leetcode.com/problems/three-divisors/

#include<bits/stdc++.h>u
using namespace std;

class Solution {
public:
    vector<int> sieve(int N){
        vector<bool> primes(N,false);
        vector<int> result;
        int p = 2;
        while (p*p <= N){
            if (primes[p] == false){
                for(int i=p*p;i<=N;i+=p){
                    primes[i] = true;
                }   
            }
            p++;
        }
        for(int i=2;i<=N;i++){
            if (primes[i] == false){
                result.push_back(i);
            }
        }
        return result;
    }
    
    bool isThree(int n) {
       const int N = 101;
        vector<int> primes = sieve(N);
        for(int i=0;i<primes.size();i++){
            if (primes[i]*primes[i] == n){
                return true;
            }
            if (primes[i]*primes[i] > n){
                return false;
            }
        }
        return false;
    }
};