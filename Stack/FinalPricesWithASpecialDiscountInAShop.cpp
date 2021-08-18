//Problem Link:- https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        const int n = prices.size();
        vector<int> result(n,0);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while (!st.empty() && st.top() > prices[i]){
                st.pop();
            }
            if (st.empty()){
                result[i] = 0;
            }
            else{
                result[i] = st.top();
            }
            st.push(prices[i]);
        }
        for(int i=0;i<n;i++){
            prices[i] -= result[i];
        }
        cout <<endl;
        return prices;
    }
};