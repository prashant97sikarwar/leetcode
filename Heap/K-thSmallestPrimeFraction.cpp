//Problem Link:- https://leetcode.com/problems/k-th-smallest-prime-fraction/

/*You are given a sorted integer array arr containing 1 and prime numbers, where all the integers 
of arr are unique. You are also given an integer k.For every i and j where 0 <= i < j < arr.length,
we consider the fraction arr[i] / arr[j].Return the kth smallest fraction considered. Return your 
answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>> pq;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pq.push({(double)arr[i] / arr[j],{arr[i],arr[j]}});
            }
        }
        while (--k){
            pq.pop();
        }
        return {pq.top().second.first,pq.top().second.second};
    }
};