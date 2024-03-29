//Problem Link:- https://leetcode.com/problems/building-boxes/

/* You have a cubic storeroom where the width, length, and height of the room are all equal to 
n units. You are asked to place n boxes in this room where each box is a cube of unit side length. There are however some rules to placing the boxes:
You can place the boxes anywhere on the floor.If box x is placed on top of the box y, then each 
side of the four vertical sides of the box y must either be adjacent to another box or to a wall.
Given an integer n, return the minimum possible number of boxes touching the floor.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBoxes(int n) {
        int ans1 = 0;
        int cur = 0;
        int ans2 = 0;
        
        while (cur + ((ans1+1) * (ans1+2)) / 2 <= n){
            cur += ((ans1+1) * (ans1+2)) / 2;
            ans1 += 1;
        }
        
        while(cur < n){
            ans2+=1;
            cur += ans2;
        }
        return ((ans1) * (ans1+1)) / 2 + ans2;
    }
};