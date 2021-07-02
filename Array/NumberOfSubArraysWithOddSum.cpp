//Problem Link:- https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod = 1e9 + 7;
        long long res = 0,odd = 0,even = 1,sm = 0;
        for(int i=0;i<arr.size();i++){
            sm += arr[i];
            if (sm&1){
                res += even%mod;
                res %= mod;
                odd++;
            }
            else{
                res += odd%mod;
                res %= mod;
                even++;
            }
        }
        return int(res%mod);
    }
};