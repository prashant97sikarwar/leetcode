//Problem Limk:- https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string,int> mp;
    int binarySearch(vector<vector<int>>& events, int idx){
        int l = idx+1, r = events.size() - 1;
        while (l <= r){
            int mid = l + (r-l)/2;
            if (events[mid][0] > events[idx][1]){
                if (events[mid-1][0] > events[idx][1]){
                    r = mid -1;
                }
                else{
                    return mid;
                }
            }
            else{
                l = mid + 1;
            }
        }
        return -1;
    }
    
    int helper(int idx, int k, vector<vector<int>>& events){
        if (k == 0 || idx >= events.size()){
            return 0;
        }
        string key = to_string(idx) + '#' + to_string(k);
        if (mp.count(key)){
            return mp[key];
        }
        int nextIdx = binarySearch(events,idx);
        int op2 = helper(idx+1,k,events);
        if (nextIdx != -1){
            int op1 = events[idx][2] + helper(nextIdx,k-1,events);
            return mp[key] = max(op1,op2);
        } 
        else{
            int op1 = events[idx][2];
            return mp[key] = max(op1,op2);
        }
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        return helper(0,k,events);
    }
};