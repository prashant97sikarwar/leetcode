//Problem Link:- https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/

/* ou are given an array target that consists of distinct integers and another integer array arr 
that can have duplicates.In one operation, you can insert any integer at any position in arr.
Return the minimum number of operations needed to make target a subsequence of arr. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        int m = arr.size();
        unordered_map<int,int> ump;
        for(int i=0;i<n;i++){
            ump[target[i]] = i;
        }
        for(int i=0;i<m;i++){
            if (ump.find(arr[i]) == ump.end())
                arr[i] = -1;
            else
                arr[i] = ump[arr[i]];
        }
        vector<int> seq;
        for(int i=0;i<m;i++){
            if (arr[i] == -1)
                continue;
            else if (seq.size() == 0)
                seq.push_back(arr[i]);
            else if (seq.size() > 0 && arr[i] > seq.back())
                seq.push_back(arr[i]);
            else{
                auto it = lower_bound(seq.begin(),seq.end(),arr[i]);
                seq[it-seq.begin()] = arr[i];
            }
        }
        return n - seq.size();
    }
};