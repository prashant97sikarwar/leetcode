//Problem Link:- https://leetcode.com/problems/determine-color-of-a-chessboard-square/

/*You are given coordinates, a string that represents the coordinates of a square of the 
chessboard.Return true if the square is white, and false if the square is black. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool squareIsWhite(string str) {
        int c = str[0]-'a';
        int n = str[1]-'0';
        if (c % 2 == 0 && n % 2 == 0)
            return true;
        if (c%2 == 1 && n % 2 == 1)
            return true;
        return false;
    }
};