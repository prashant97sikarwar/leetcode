//Problem Link:- https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,vector<int>>> pq;
        int n = nums1.size();
        int m = nums2.size();
        for(int i=0;i<=min(n-1,k);i++){
            for(int j=0;j<=min(m-1,k);j++){
                int sm = nums1[i] + nums2[j];
                if (pq.size() == k){
                    if (sm >= pq.top().first){
                        continue;
                    }
                    else{
                        pq.pop();
                        pq.push({sm,{nums1[i],nums2[j]}});
                    }
                }
                else{
                    pq.push({sm,{nums1[i],nums2[j]}});
                }
            }
        }
        vector<vector<int>> result;
        while (pq.size() > 0){
            auto node = pq.top();
            pq.pop();
            result.push_back(node.second);
        }
        return result;
    }
};