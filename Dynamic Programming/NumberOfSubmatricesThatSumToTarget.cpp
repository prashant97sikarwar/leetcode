//Problem Link:- https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& nums, int k) {
        int n = nums.size();
        int m = nums[0].size();
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                nums[i][j] += nums[i][j-1];
            }
        }
        unordered_map<int,int> mp;
        int res = 0;
        for(int c1=0;c1<m;c1++){
            for(int c2=c1;c2<m;c2++){
                mp.clear();
                mp[0] = 1;
                int sm = 0;
                for(int row=0;row<n;row++){
                    sm += nums[row][c2] - (c1 == 0 ? 0 : nums[row][c1-1]);
                    if (mp.count(sm-k) > 0){
                        res += mp[sm-k];
                    }
                    mp[sm]++;
                }
            }
        }
        return res;
    }
};