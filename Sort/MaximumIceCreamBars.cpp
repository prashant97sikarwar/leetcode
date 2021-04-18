//Problem Link:- https://leetcode.com/problems/maximum-ice-cream-bars/

/*At the store, there are n ice cream bars. You are given an array costs of length n, where 
costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to 
spend, and he wants to buy as many ice cream bars as possible. Return the maximum number of ice 
cream bars the boy can buy with coins coins.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int res = 0;
        for(int i=0;i<costs.size();i++){
            if (coins >= costs[i]){
                res++;
                coins -= costs[i];
            }
            else{
                break;
            }
        }
        return res;      
    }
};