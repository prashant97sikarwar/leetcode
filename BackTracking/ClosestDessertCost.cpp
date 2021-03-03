//Problem Link:- https://leetcode.com/problems/closest-dessert-cost/

/*You would like to make dessert and are preparing to buy the ingredients. You have n ice cream 
base flavors and m types of toppings to choose from. You must follow these rules when making your 
dessert:
1.There must be exactly one ice cream base.
2.You can add one or more types of topping or have no toppings at all.
3.There are at most two of each type of topping.
You are given three inputs:
1.baseCosts, an integer array of length n, where each baseCosts[i] represents the price of the ith 
    ice cream base flavor.
2.toppingCosts, an integer array of length m, where each toppingCosts[i] is the price of one of the 
    ith topping.
3.target, an integer representing your target price for dessert.
You want to make a dessert with a total cost as close to target as possible.Return the closest 
possible cost of the dessert to target. If there are multiple, return the lower one. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cost;
    int helper(int a, int b){
        if (a == 0)
            return b;
        if (b == 0)
            return a;
        if (abs(cost-a) == abs(cost-b))
            return (a < b) ? a : b; 
        return (abs(cost-a) < abs(cost-b) ? a : b);
    }
    
    int dfs(vector<int>& top, int idx,int sm){
        if (idx >= top.size()){
            return sm;
        }
        int p1 = dfs(top,idx+1,sm);
        int p2 = dfs(top,idx+1,sm+top[idx]);
        int p3 = dfs(top,idx+1,sm+(2*top[idx]));
        sm = helper(p1,helper(p2,p3));
        return sm;
    }
    
    int closestCost(vector<int>& base, vector<int>& top, int target) {
        cost = target;
        int ans  = 0;
        for(int i=0;i<base.size();i++){
            ans = helper(dfs(top,0,base[i]),ans);
        }
        return ans;
    }
};