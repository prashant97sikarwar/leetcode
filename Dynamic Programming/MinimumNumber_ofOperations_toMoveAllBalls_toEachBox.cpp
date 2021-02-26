//problem Link:- https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

/* You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the 
ith box is empty, and '1' if it contains one ball.In one operation, you can move one ball from a 
box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, 
there may be more than one ball in some boxes.Return an array answer of size n, where answer[i] is 
the minimum number of operations needed to move all the balls to the ith box.Each answer[i] is 
calculated considering the initial state of the boxes. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes){
        int n = boxes.size();
        vector<int> left(n,0), right(n,0), ans(n,0);
        int balls = 0;
        balls = boxes[0] - '0';
        for(int i=1;i<n;i++){
            left[i] = left[i-1] + balls;
            balls += (boxes[i] - '0');
        }
        balls = boxes[n-1]-'0';
        for(int i=n-2;i>= 0;i--){
            right[i] = right[i+1] + balls;
            balls += (boxes[i] - '0');
        }
        for(int i=0;i<n;i++){
            ans[i] += (left[i] + right[i]);
        }
        return ans;
    }
};