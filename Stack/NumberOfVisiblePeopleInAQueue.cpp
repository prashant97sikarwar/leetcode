//Problem Link:- https://leetcode.com/problems/number-of-visible-people-in-a-queue/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        const int n = heights.size();
        vector<int> result(n,1);
        for(int i=n-1;i>=0;i--){
            int cnt = 0;
            while (!st.empty() && heights[i] > heights[st.top()]){
                st.pop();
                cnt++;
            }
            if (st.empty()){
                if (i == n-1){
                    result[i] = 0;
                }
                else{
                    result[i] = cnt;
                }
            }
            else{
                result[i] = cnt + 1;   
            }
            st.push(i);
        }
        return result;
    }
};