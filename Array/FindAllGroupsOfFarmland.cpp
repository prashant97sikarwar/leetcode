//Problem Link:- https://leetcode.com/problems/find-all-groups-of-farmland/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        const int row = land.size();
        const int col = land[0].size();
        vector<vector<int>> result;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if (land[i][j]){
                    int x = i, y = j;
                    
                    for(x=i;x<row && land[x][j];x++){
                        for(y=j;y<col && land[x][y];y++){
                            land[x][y] = 0;
                        }
                    }
                    result.push_back({i,j,x-1,y-1});
                }
            }
        }
        return result;
    }
};