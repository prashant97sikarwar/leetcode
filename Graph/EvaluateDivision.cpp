//Problem Link:- https://leetcode.com/problems/evaluate-division/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        unordered_map<string,unordered_map<string,double>> graph;
public:
    double dfs(string start, string dest,unordered_set<string> &vis){
        if (graph.find(start) == graph.end()){
            return -1;
        }
        if(graph[start].find(dest)!=graph[start].end())
            return graph[start][dest];
        vis.insert(start);
        for(auto i:graph[start])
        {
            //we dont want to revisit our previously visited strings
            if(!vis.count(i.first))
            {
                double ans=dfs(i.first,dest,vis);
                if(ans!=-1.0)
                    return (double)ans * (i.second);
            }       
        }
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0;i<eq.size();i++){
            string a = eq[i][0];
            string b = eq[i][1];
            double val = values[i];
            graph[a].insert({b,val});
            graph[b].insert({a,(double)1/val});
        }
        vector<double> res;
        for(int i=0;i<queries.size();i++){
            unordered_set<string> vis;
            double ans = dfs(queries[i][0],queries[i][1],vis);
            res.push_back(ans);
        }
        return res;
    }
};