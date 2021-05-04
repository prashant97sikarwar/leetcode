//Problem Link:- https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        if (n == 1){
            return 1;
        }
        sort(arr.begin(),arr.end());
        int res = 0;
        for(int i=0;i<n;i++){
            if (arr[i] > res){
                res++;
            }
        }
        return res;
    }
};