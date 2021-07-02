//Problem Link:- https://leetcode.com/problems/cyclically-rotating-a-grid/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        
        int bottom = grid.size() - 1, right = grid[0].size()-1;//Bottom right coordinates
        int top = 0, left = 0;//Top left coordinates
        
        while(bottom>top&&right>left){
            int total_layer_elements = 2*(bottom-top+1) + 2*(right-left+1) - 4;
            int t = k%total_layer_elements;
            while(t--){
                int temp = grid[top][left];
                
                for(int j = left; j<right; j++){
                    grid[top][j] = grid[top][j+1];
                }
                
                for(int i = top; i<bottom; i++){
                    grid[i][right] = grid[i+1][right];
                }
                
                for(int j = right; j>left; j--){
                    grid[bottom][j] = grid[bottom][j-1]; 
                }
                
                for(int i = bottom; i>top; i--){
                    grid[i][left] = grid[i-1][left];
                }
                grid[top+1][left] = temp;
            }
            top++, left++, bottom--, right--;
        }
        return grid;
    }
};