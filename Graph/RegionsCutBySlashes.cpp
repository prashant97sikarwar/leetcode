//Problem Link:- https://leetcode.com/problems/regions-cut-by-slashes/

/* In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank
space.  These characters divide the square into contiguous regions.(Note that backslash 
characters are escaped, so a \ is represented as "\\".).Return the number of regions. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int i,int j, vector<vector<int>> &arr){
        if (i < 0 || j < 0 || i >= arr.size() || j >= arr.size() || arr[i][j] == 1)
            return; 
        arr[i][j] = 1;
        dfs(i+1,j,arr);
        dfs(i-1,j,arr);
        dfs(i,j-1,arr);
        dfs(i,j+1,arr);
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> arr(3*n,vector<int>(3*n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (grid[i][j] == '/'){
                    arr[3*i][3*j+2] = 1;
                    arr[3*i+1][3*j+1] = 1;
                    arr[3*i+2][3*j] = 1;
                }
                else if (grid[i][j] == '\\'){
                    arr[3*i][3*j] = 1;
                    arr[3*i+1][3*j+1] = 1;
                    arr[3*i+2][3*j+2] = 1;
                }
            }
        }
        int count = 0;
        for(int i=0;i<3*n;i++){
            for(int j=0;j<3*n;j++){
                if (arr[i][j] == 0){
                    dfs(i,j,arr);
                    count++;
                }
            }
        }
        return count;
    }
};