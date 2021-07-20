//Problem Link:- https://leetcode.com/problems/132-pattern/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        const int n = nums.size();
        if (n < 3){
            return false;
        }
        vector<int> minarr(n);
        minarr[0] = nums[0];
        for(int i=1;i<n;i++){
            minarr[i] = min(minarr[i-1],nums[i]);
        }
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while (!st.empty() && st.top() <= minarr[i]){
                st.pop();
            }
            while (!st.empty() && st.top() < nums[i]){
                return true;
            }
            st.push(nums[i]);
        }
        return false;
    }
};