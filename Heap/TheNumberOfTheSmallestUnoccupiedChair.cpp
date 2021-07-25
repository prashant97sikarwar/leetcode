//Problem Link:- https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int k) {
        const int n = times.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> busy;
        priority_queue<int,vector<int>,greater<int>> free;
        for(int i=0;i<n;i++){
            times[i].push_back(i);
        }
        sort(times.begin(),times.end());
        int newchair = 0;
        for(int i=0;i<n;i++){
            int arr = times[i][0];
            int dep = times[i][1];
            int idx = times[i][2];
            while (!busy.empty() && busy.top().first <= arr){
                free.push(busy.top().second);
                busy.pop();
            }
            if (free.empty()){
                if (idx == k){
                    return newchair;
                }
                busy.push({dep,newchair});
                newchair++;
            }
            else{
                int x = free.top();
                free.pop();
                if (idx == k){
                    return x;
                }
                busy.push({dep,newchair});
            }
        }
        return -1;
    }
};