//Problem link:- https://leetcode.com/problems/last-day-where-you-can-still-cross/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    bool helper(int key,vector<vector<int>>& dp,int row,int col){
        set<pair<int,int>> visited;
        queue<pair<int,int>> pq;
        for(int i=0;i<col;i++){
            if (dp[0][i] == 0){
                pq.push({0,i});
                visited.insert({0,i});
            }
        }
        while (!pq.empty()){
            pair<int,int> node = pq.front();
            pq.pop();
            int x = node.first;
            int y = node.second;
            if (x == row-1){
                return true;
            }
            for(int k=0;k<4;k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && ny >= 0 && nx < row && ny < col && dp[nx][ny] == 0 && !visited.count({nx,ny})){
                    pq.push({nx,ny});
                    visited.insert({nx,ny});
                }
            }
        }
        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1, right = row*col;
        int result = 0, prevMid = 0;
        vector<vector<int>> dp(row,vector<int> (col,0));
        while (left <= right){
            int mid = left + (right-left)/2;
            if (mid > prevMid){
                for(int i=prevMid;i<mid;i++){
                    int x = cells[i][0];
                    int y = cells[i][1];
                    dp[x-1][y-1] = 1;
                }
            }
            else{
                for(int i=mid;i<prevMid;i++){
                    int x = cells[i][0];
                    int y = cells[i][1];
                    dp[x-1][y-1] = 0;
                }
            }
            prevMid = mid;
            if (helper(mid,dp,row,col)){
                result = max(result,mid);
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return result;
    }
};