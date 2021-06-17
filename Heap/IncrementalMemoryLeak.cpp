//Problem Link:- https://leetcode.com/problems/incremental-memory-leak/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> memLeak(int m1, int m2){
        priority_queue<pair<int,int>> pq;
        pq.push({m2,1});
        pq.push({m1,2});
        int cnt = 1;
        int memo, num;
        while (!pq.empty()){
            auto x = pq.top();
            pq.pop();
            memo = x.first;
            num = x.second;
            if (memo < cnt){
                break;
            }
            else{
                memo -= cnt;
                pq.push({memo,num});
            }
            cnt++;
        }
        vector<int> result;
        result.push_back(cnt);
        auto y = pq.top();
        if (num == 2){
            result.push_back(memo);
            result.push_back(y.first);
        }
        else{
            result.push_back(y.first);
            result.push_back(memo);
        }
        return result;
    }
};