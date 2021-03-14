//Problem Link:- https://leetcode.com/problems/maximum-average-pass-ratio/

/*You are given a 2D integer array classes, where classes[i] = [passi, totali].You are also 
given an integer extraStudents. There are another extraStudents brilliant students that are 
guaranteed to pass the exam of any class they are assigned to. You want to assign each of 
the extraStudents students to a class in a way that maximizes the average pass ratio across 
all the classes.Return the maximum possible average pass ratio after assigning the extraStudents 
students. Answers within 10-5 of the actual answer will be accepted. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int ext) {
        priority_queue<pair<double,double>> pq;
        double res = 0;
        for(int i=0;i<classes.size();i++){
            auto curr = classes[i];
            double ratio = (double)curr[0] / curr[1];
            double next = (double)(curr[0]+1) / (curr[1]+1);
            pq.push({next-ratio,i});
        }
        while (!pq.empty() && ext > 0){
            double node = pq.top().second;
            classes[node][0] += 1;
            classes[node][1] += 1;
            pq.pop();
            ext -= 1;
            double ahead = (double)(classes[node][0]+1)/(classes[node][1]+1);
            double present = (double)(classes[node][0])/(classes[node][1]);
            pq.push({ahead-present,node});
        }
        for(auto curr : classes){
            res += (double)(curr[0]) / curr[1];
        }
        return res / classes.size();
    }
};