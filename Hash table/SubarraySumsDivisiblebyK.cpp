//Problem Link:- https://leetcode.com/problems/subarray-sums-divisible-by-k/

/*Given an array A of integers, return the number of (contiguous, non-empty) subarrays that 
have a sum divisible by K. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int sm = 0;
        unordered_map<int,int> mp;
        int n = A.size();
        int res = 0;
        mp[0] = 1;
        for(int i=0;i<n;i++){
            sm += A[i];
            int tot = (sm % K);
            if (tot < 0)
                tot += K;
            if (mp.count(tot) > 0){
                res += mp[tot];
                mp[tot]++;
            }
            else{
                mp[tot]++;
            }
        }
        return res;
    }
};