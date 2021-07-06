//Problem Link:- https://leetcode.com/problems/find-eventual-safe-states/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    vector<int> graph[10005];
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& nums) {
        int nodeCount = nums.size();
        vector<int> indegree(nodeCount,0);
        for(int i=0;i<nodeCount;i++){
            vector<int> nie = nums[i];
            for(int j=0;j<nie.size();j++){
                graph[nie[j]].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> pq;
        for(int i=0;i<nodeCount;i++){
            if (indegree[i] == 0){
                pq.push(i);
            }
        }
        vector<int> result;
        while (!pq.empty()){
            int node = pq.front();
            pq.pop();
            result.push_back(node);
            for(int child : graph[node]){
                indegree[child]--;
                if (indegree[child] == 0){
                    pq.push(child);
                }
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};