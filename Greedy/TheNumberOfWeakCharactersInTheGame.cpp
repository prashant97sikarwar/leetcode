//Problem Link:- https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    static bool cmp(vector<int> &a, vector<int> &b){
        if (a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& nums) {
        const int n = nums.size();
        sort(nums.begin(),nums.end(),cmp);

        int mx = INT_MIN;
        int result = 0;

        for(int i=n-1;i>=0;i--){
            if (nums[i][1] < mx){
                result++;
            }
            mx = max(mx,nums[i][1]);
        }
        return result;
    }
};