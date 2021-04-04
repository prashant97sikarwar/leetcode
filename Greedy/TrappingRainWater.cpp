//Problem Link:- https://leetcode.com/problems/trapping-rain-water/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n+2,0);
        vector<int> right(n+2,0);
        for(int i=1;i<=n;i++){
            left[i] = max(left[i-1],height[i-1]);
        }
        for(int i=n;i>=1;i--){
            right[i] = max(right[i+1],height[i-1]);
        }
        int res = 0;
        for(int i=1;i<=n;i++){
            res += (min(left[i],right[i]) - height[i-1]);
        }
        return res;
    }
};