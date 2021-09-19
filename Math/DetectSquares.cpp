//Problem link;- https://leetcode.com/problems/detect-squares/

#include<bits/stdc++.h>
using namespace std;

class DetectSquares {
    
public:
    int dp[1005][1005];
    vector<pair<int,int>> nums;
    DetectSquares() {
        memset(dp,0,sizeof(dp));
        nums.clear();
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        nums.push_back({x,y});
        dp[x][y] += 1;
        
    }
    
    bool helper(int x, int y, int qx, int qy){
        int difX = abs(qx-x);
        int difY = abs(qy-y);
        
        if (x == qx && y == qy){
            return false;
        }
        if (difX == difY){
            return true;
        }
        return false;
    }
    
    int count(vector<int> point) {
        int qx = point[0];
        int qy = point[1];
        int result = 0;
        for(int i=0;i<nums.size();i++){
            int x = nums[i].first;
            int y = nums[i].second;
            if (helper(x,y,qx,qy)){
                int fx = x;
                int fy = qy;
                int sx = qx;
                int sy = y;
                
                result += (dp[fx][fy] * dp[sx][sy]);
            }
        }
        return result;
    }
};

