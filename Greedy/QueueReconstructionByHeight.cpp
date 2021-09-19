//Problem Link:- https://leetcode.com/problems/queue-reconstruction-by-height/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        const int n = people.size();
        sort(people.begin(),people.end());
        vector<vector<int>> result(n);
        for(int i=0;i<people.size();i++){
            int val = people[i][0];
            int pos = people[i][1] + 1;
            int cnt = 0;
            for(int j=0;j<n;j++){
                if (result[j].size() == 0 || result[j][0] == val){
                    cnt++;
                    if (cnt == pos){
                        result[j] = people[i];
                        break;
                    }
                }
            }
        }
        return result;
    }
};