//Problem Link:- https://leetcode.com/problems/maximize-distance-to-closest-person/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxDist = 0;
        const int n = seats.size();
        int dist = 0;
        for(int i=0;i<n;i++){
            if (seats[i] == 1){
                maxDist = max(maxDist, dist);
                dist = 0;
            }
            else{
                dist += 1;
            }
        }
        int op1 = (maxDist % 2 == 0) ? maxDist / 2 : maxDist / 2 + 1;
        int op2 = -1, op3 = -1;
        if (seats[n-1] == 0){
            if (dist >= op1){
                maxDist = dist;
                op2 = maxDist;
            }
        }
        dist = 0;
        int i = 0;
        while(seats[i] != 1){
            dist++;
            i++;
        }
        if (dist >=  op1){
            op3 = dist;
        }
        return max(op1, max(op2,op3));
    }
};