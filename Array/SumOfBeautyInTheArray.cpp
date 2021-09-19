//Problem link:- https://leetcode.com/problems/sum-of-beauty-in-the-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        const int n = nums.size();
        
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        left[0] = nums[0];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1], nums[i]);
        }
        
        right[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            right[i] = min(right[i+1],nums[i]);
        }
        int result = 0;
        vector<bool> mark(n,false);
        for(int i=1;i<n-1;i++){
            if (left[i] == right[i] && left[i] != left[i-1] && right[i] != right[i+1]){
                mark[i] = true;
                result += 2;
            }
        }
        for(int i=1;i<n-1;i++){
            if (nums[i-1] < nums[i] && nums[i+1] > nums[i] && mark[i] == false){
                result++;
            }
        }
        return result;
    }
};