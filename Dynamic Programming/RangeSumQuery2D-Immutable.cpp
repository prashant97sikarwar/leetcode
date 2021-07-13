//Problem Link:- https://leetcode.com/problems/range-sum-query-2d-immutable/

#include<bits/stdc++.h>
using namespace std;

class NumMatrix {
    private:
    int dp[205][205];
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j] = matrix[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1+=1, col1+=1, row2+=1,col2+=1;
        int ans = dp[row2][col2] - dp[row1-1][col2] - dp[row2][col1-1] + dp[row1-1][col1-1];
        return ans;
    }
};
