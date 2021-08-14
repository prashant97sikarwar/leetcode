//Problem Link:- https://leetcode.com/problems/gas-station/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();
        int fuel = 0;
        int idx = -1;
        bool flag = false;
        for(int i=0;i<n;i++){
            if (fuel + gas[i] < cost[i]){
                fuel = 0;
                flag = false;
                idx = -1;
            }
            else{
                if (flag == false){
                    idx = i;
                    flag = true;
                }
                fuel += gas[i] - cost[i];
            }
        }
        for(int i=0;i<n && i < idx;i++){
            if (fuel + gas[i] < cost[i]){
                fuel = 0;
                flag = false;
                idx = -1;
            }
            else{
                if (flag == false){
                    idx = i;
                    flag = true;
                }
                fuel += gas[i] - cost[i];
            }
        }
        return idx;
    }
};