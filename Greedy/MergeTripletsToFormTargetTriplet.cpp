//Problem Link:- https://leetcode.com/problems/merge-triplets-to-form-target-triplet/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        bool flag1 = false,flag2 = false,flag3 = false;
        for(int i=0;i<n;i++){
            if (triplets[i][0] == target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2]){
                flag1 = true;
            }
        }
        for(int i=0;i<n;i++){
            if (triplets[i][1] == target[1] && triplets[i][0] <= target[0] && triplets[i][2] <= target[2]){
                flag2 = true;
            }
        }
        for(int i=0;i<n;i++){
            if (triplets[i][2] == target[2] && triplets[i][0] <= target[0] && triplets[i][1] <= target[1]){
                flag3 = true;
            }
        }
        if (flag1 && flag2 && flag3){
            return true;
        }
        return false;
    }
};