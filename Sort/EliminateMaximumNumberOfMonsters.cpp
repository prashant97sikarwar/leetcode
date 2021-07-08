//Problem Link:- https://leetcode.com/problems/eliminate-maximum-number-of-monsters/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<float> nums(n);
        for(int i=0;i<n;i++){
            nums[i] = (float)dist[i] / speed[i];
        }
        sort(nums.begin(),nums.end());
        
        int time = 1;
        int res = 1;
        for(int i=1;i<n;i++){
            if (time < nums[i]){
                res++;
                time++;
            }
            else{
                break;
            }
        }
        return res;
    }
};