//Problem Link:- https://leetcode.com/problems/asteroid-collision/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if (st.empty()){
                st.push(nums[i]);
            }
            else if (nums[i] > 0){
                st.push(nums[i]);
            }
            else if (nums[i] < 0){
                if (!st.empty() && st.top() < 0){
                    st.push(nums[i]);
                }
                else if (!st.empty() && abs(nums[i]) == st.top()){
                    st.pop();
                    continue;
                }
                else if (!st.empty() && abs(nums[i]) < st.top()){
                    continue;
                }
                else if (!st.empty() && abs(nums[i]) > abs(st.top())){
                    while (!st.empty() && abs(nums[i]) > st.top() && st.top() > 0){
                        st.pop();
                    }
                    if (!st.empty() && abs(nums[i]) == st.top()){
                        st.pop();
                        continue;
                    }
                    if (st.empty() || st.top() < 0){
                        st.push(nums[i]);
                    }
                    else{
                        continue;
                    }
                }
                
            }
        }
        vector<int> result;
        while (!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};