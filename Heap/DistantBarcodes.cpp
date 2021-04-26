//Problem Link:- https://leetcode.com/problems/distant-barcodes/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> ump;
        for(int i=0;i<n;i++){
            ump[barcodes[i]]++;
        }
        for(auto x : ump){
            pq.push({x.second,x.first});
        }
        int cnt = 0;
        int num;
        for(int i=0;i<n;i+=2){
            if (cnt == 0){
                cnt = pq.top().first;
                num = pq.top().second;
                pq.pop();
            }
            barcodes[i] = num;
            cnt--;
        }
        for(int i=1;i<n;i+=2){
            if (cnt == 0){
                cnt = pq.top().first;
                num = pq.top().second;
                pq.pop();
            }
            barcodes[i] = num;
            cnt--;
        }
        return barcodes;
    }
};