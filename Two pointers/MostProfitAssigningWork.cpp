//Problem Link:- https://leetcode.com/problems/most-profit-assigning-work/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    int maxProfitAssignment(vector<int>& diff, vector<int>& nums, vector<int>& worker){
        int n = diff.size();
        vector<int> profit(n,0);
        vector<pair<int,int>> freq;
        for(int i=0;i<n;i++){
            freq.push_back({diff[i],nums[i]});
        }
        sort(freq.begin(),freq.end());
        profit[0] = freq[0].second;
        for(int i=1;i<n;i++){
            profit[i] = max(profit[i-1],freq[i].second);
        }
        sort(diff.begin(),diff.end());
        for(int i=0;i<n;i++){
            cout << profit[i] <<" ";
        }
        long long res = 0;
        for(int i=0;i<worker.size();i++){
            auto it = upper_bound(diff.begin(),diff.end(),worker[i]);
            if (it == diff.begin()){
                continue;
            }
            it--;
            int idx = it - diff.begin();
            res += profit[idx];
        }
        return (int)res;
    }
};