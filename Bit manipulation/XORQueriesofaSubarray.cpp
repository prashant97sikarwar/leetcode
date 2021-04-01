//Problem Link:- https://leetcode.com/problems/xor-queries-of-a-subarray/

/* Given the array arr of positive integers and the array queries where queries[i] = [Li, Ri], 
for each query i compute the XOR of elements from Li to RiReturn an array containing the result 
for the given queries. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefix;
        prefix.push_back(0);
        prefix.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            prefix.push_back(arr[i] ^ prefix.back());
        }
        vector<int> ans; 
        for(int i=0;i<queries.size();i++){
            int x = queries[i][0];
            int y = queries[i][1];
            ans.push_back(prefix[y+1] ^ prefix[x]);
        }
        return ans;
    }
};