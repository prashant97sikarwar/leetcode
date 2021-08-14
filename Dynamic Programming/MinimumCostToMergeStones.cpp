//Problem Link:- https://leetcode.com/problems/minimum-cost-to-merge-stones/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dp[31][31];
public:
    int mergeStones(vector<int>& stones, int k) {
        const int len = stones.size();
        vector<int> prefix(len+1,0);
        for(int i=0;i<len;i++){
            prefix[i+1] = prefix[i] + stones[i];
        }
        if ((len-1)%(k-1) != 0){
            return -1;
        }
        for(int sz=k;sz<=len;sz++){
            for(int i=0;i<len-sz+1;i++){
                int j = i+sz-1;
                
                dp[i][j] = INT_MAX;
                for(int m=i;m<j;m+=k-1){
                    dp[i][j] = min(dp[i][j],dp[i][m] + dp[m+1][j]);
                }
                if ((j-i)%(k-1) == 0){
                    dp[i][j] += prefix[j+1] - prefix[i];
                }
            }
        }
        return dp[0][len-1];
    }
};