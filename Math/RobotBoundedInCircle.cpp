//Problem Link:- https://leetcode.com/problems/robot-bounded-in-circle/

#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
class Solution {
public:
    bool isRobotBounded(string s) {
        int x = 0,y = 0;
        int dir = 0;
        for(int i=0;i<s.length();i++){
            if (s[i] == 'G'){
                x += dx[dir];
                y += dy[dir];
            }
            else if(s[i] == 'L'){
                if (dir == 0){
                    dir = 3;
                }
                else if (dir == 1){
                    dir = 2;
                }
                else if (dir == 2){
                    dir = 0;
                }
                else if (dir == 3){
                    dir = 1;
                }
            }
            else if (s[i] == 'R'){
                if (dir == 0){
                    dir = 2;
                }
                else if (dir == 1){
                    dir = 3;
                }
                else if (dir == 2){
                    dir = 1;
                }
                else if (dir == 3){
                    dir = 0;
                }
            }
        }
        if (dir != 0 || (x == 0 && y == 0)){
            return true;
        }
        return false;
    }
};