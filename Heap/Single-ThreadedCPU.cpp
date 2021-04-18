//Problem Link:- https://leetcode.com/problems/single-threaded-cpu/

/* Implement non-pre-emptive shortest job first scheduling algorithm */

#include<bits/stdc++.h>
using namespace std;

class Compare{
public:
    bool operator() (vector<int>& v1, vector<int>& v2){   
        if(v1[1]==v2[1]) return (v1[2]>v2[2]);
        return (v1[1]>v2[1]);
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i=0; i<tasks.size(); i++) tasks[i].push_back(i); 
        sort(tasks.begin(), tasks.end());

        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        vector<int> ans;
        
        int i= 0;
        long long int time= 0;
        bool isFirst= true;
        while(i < tasks.size() || !pq.empty()){
            if (pq.empty()){
                int enqTime = tasks[i][0];
                for(;i<tasks.size();i++){
                    if(tasks[i][0]!=enqTime) break;
                    pq.push(tasks[i]);
                }
            }
            if(!pq.empty()){
                if(isFirst){
                    time = pq.top()[1]+pq.top()[0]; 
                    isFirst= false;
                }
                else time += pq.top()[1];

                ans.push_back(pq.top()[2]);
                pq.pop();
                while(i<tasks.size() && ((long long int)tasks[i][0])<=time){
                    pq.push(tasks[i]);
                    i++;
                }

            }
        }
		return ans;
        }
};