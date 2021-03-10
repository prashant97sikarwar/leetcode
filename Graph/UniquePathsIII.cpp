//Problem Link:- https://leetcode.com/problems/unique-paths-iii/

/* On a 2-dimensional grid, there are 4 types of squares:
1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk 
over every non-obstacle square exactly once. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m;
    int n;
    int pathse;
    int startx;
    int starty;
    int endx;
    int endy;
    int ans;
    
    void dfs(vector<vector<int>> grid, int x, int y,int path){
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == -1)
            return;
        if (x == endx && y == endy && pathse == path){
            ans++;
            return;
        }
        grid[x][y] = -1;
        dfs(grid,x-1,y,path+1);
        dfs(grid,x,y+1,path+1);
        dfs(grid,x+1,y,path+1);
        dfs(grid,x,y-1,path+1);
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        pathse = m * n;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (grid[i][j] == 1){
                    startx = i;
                    starty = j;
                }
                else if (grid[i][j] == 2){
                    endx = i;
                    endy = j;
                }
                else if (grid[i][j] == -1){
                    pathse--;
                }
            }
        }
        dfs(grid,startx, starty,1);
        return ans;
        
    }
};