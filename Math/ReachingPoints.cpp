//Problem Link:- https://leetcode.com/problems/reaching-points/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(tx<sx || ty<sy){
            return false;
        }
        if(tx==sx){
            return ((ty-sy)%sx==0);
        }
        if(ty==sy){
            return ((tx-sx)%sy==0);
        }
        if(ty>tx){
            return reachingPoints(sx,sy,tx,ty-tx);
        }
        return reachingPoints(sx,sy,tx-ty,ty);
    }
};