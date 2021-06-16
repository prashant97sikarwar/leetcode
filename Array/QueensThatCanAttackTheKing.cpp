//Problem Link:- https://leetcode.com/problems/queens-that-can-attack-the-king/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    void helper(vector<vector<int>>&result,vector<vector<int>> &mat,int x,int y,int i,int j){
        while(x >= 0 && y >= 0 && x < 8 && y < 8){
            if (mat[x][y] == 1){
                result.push_back({x,y});
                break;
            }
            x += i;
            y += j;
        }
    }
    
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> mat(8,vector<int> (8,0));
        for(int i=0;i<queens.size();i++){
            int cx = queens[i][0];
            int cy = queens[i][1];
            mat[cx][cy] = 1;
        }
        int kx = king[0];
        vector<vector<int>> result;
        int ky = king[1];
        int dx[] = {-1,-1,0,1,1,1,0,-1};
        int dy[] = {0,1,1,1,0,-1,-1,-1};
        for(int i=0;i<8;i++){
            helper(result,mat,kx,ky,dx[i],dy[i]);
        }
        return result;
    }
};