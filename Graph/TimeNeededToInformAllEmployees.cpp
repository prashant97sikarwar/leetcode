//Problem Link:- https://leetcode.com/problems/time-needed-to-inform-all-employees/

"""A company has n employees with a unique ID for each employee from 0 to n - 1. The head
of the company has is the one with headID.Each employee has one direct manager given in 
the manager array where manager[i] is the direct manager of the i-th employee, 
manager[headID] = -1. Also it's guaranteed that the subordination relationships have a 
tree structure.The head of the company wants to inform all the employees of the company 
of an urgent piece of news. He will inform his direct subordinates and they will inform 
their subordinates and so on until all employees know about the urgent news.The i-th 
employee needs informTime[i] minutes to inform all of his direct subordinates (i.e After 
informTime[i] minutes, all his direct subordinates can start spreading the news).Return 
the number of minutes needed to inform all the employees about the urgent news."""

class Solution {
    void dfs(unordered_map<int, vector<int>>&graph, int i, vector<int>& informTime, int &res, int cur) {

            cur += informTime[i];
            res = max(res,cur);
            for(auto child : graph[i]){
                dfs(graph,child,informTime,res,cur);
            }
            
        }
        
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        unordered_map<int,vector<int>> graph;
        for(int i=0;i<n;i++){
            if (i != headID)
                graph[manager[i]].push_back(i);
        }
        int res = 0;
        int cur = 0;
        dfs(graph,headID,informTime,res,cur);
        return res;
        
    }
};

