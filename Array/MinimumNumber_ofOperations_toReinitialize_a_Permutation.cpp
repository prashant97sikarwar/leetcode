//Problem Link:- https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n,0), arr(n,0);
        for(int i=0;i<n;i++){
            perm[i] = i;
        }
        int cnt=0,i;
        while (1){
            cnt++;
            for(int i=0;i<n;i++){
                if (i%2 == 0)
                    arr[i] = perm[i / 2];
                else
                    arr[i] = perm[n / 2 + (i-1)/2];
            }
            perm = arr;
            for(i=0;i<n;i++){
                if (arr[i] != i)
                    break;
            }
            if (i == n)
                return cnt;
        }
    }
};