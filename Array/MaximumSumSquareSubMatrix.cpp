//Problem Link:- https://www.interviewbit.com/problems/maximum-sum-square-submatrix/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > &nums, int k) {
    int n = nums.size();
    vector<vector<int>> mat(n+1,vector<int> (n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mat[i][j] = mat[i-1][j] + mat[i][j-1] + nums[i-1][j-1] - mat[i-1][j-1];
        }
    }
    int res = INT_MIN;
    for(int i=1;i<=n-k+1;i++){
        for(int j=1;j<=n-k+1;j++){
            int add = mat[i-1][j-1];
            int sub1 = mat[i-1][j+k-1];
            int sub2 = mat[i+k-1][j-1];
            int tot = mat[i+k-1][j+k-1] + add - sub1 - sub2;
            res = max(res,tot);
        }
    }
    return res;
}
