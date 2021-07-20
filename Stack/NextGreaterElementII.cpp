//Problem Link:- https://leetcode.com/problems/next-greater-element-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while (!st.empty() && nums[i] >= nums[st.top()]){
                st.pop();
            }
            result[i] = (st.empty() ? -1 : nums[st.top()]);
            st.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while (!st.empty() && nums[i] >= nums[st.top()]){
                st.pop();
            }
            result[i] = (st.empty() ? -1 : nums[st.top()]);
            st.push(i);
        }
        return result;
    }
};