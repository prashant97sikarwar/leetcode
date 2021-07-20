//Problem Link:- https://leetcode.com/problems/sum-of-subarray-minimums/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        arr.push_back(0);
        const int n = arr.size();
        stack<int> st;
        long long res = 0;
        for(int i=0;i<n;i++){
            while (!st.empty() && arr[st.top()] > arr[i]){
                int cur = st.top();
                st.pop();
                int left = (st.empty() ? -1 : st.top());
                res=(((((i-cur)%mod*1LL*(cur-left)%mod)%mod)*arr[cur]%mod)%mod + res%mod)%mod;
            }
            st.push(i);
        }
        return res%mod;
    }
};