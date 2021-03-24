//Problem Link:- https://leetcode.com/problems/number-of-orders-in-the-backlog/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        int mod = 1e9 + 7;
        priority_queue<vector<int>> buy;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> sell;
        for(auto ord : orders){
            int p = ord[0];
            int n = ord[1];
            int t = ord[2];
            if (t == 0){
                while(sell.size() > 0 && sell.top()[0] <= p && n){
                    auto curr = sell.top();
                    if (curr[1] > n){
                        curr[1] -= n;
                        sell.pop();
                        sell.push(curr);
                        n = 0;
                    }
                    else{
                        n -= curr[1];
                        sell.pop();
                    }
                }
                if (n)
                    buy.push({p,n,t});
            }
            else{
                while(buy.size() > 0 && buy.top()[0] >= p && n){
                    auto curr = buy.top();
                    if (curr[1] > n){
                        curr[1] -= n;
                        buy.pop();
                        buy.push(curr);
                        n = 0;
                    }
                    else{
                        n -= curr[1];
                        buy.pop();
                    }
                }
                if (n)
                    sell.push({p,n,t});
            }
        }
        int res = 0;
        while (buy.size() >  0){
            res += buy.top()[1];
            res %= mod;
            buy.pop();
        }
        while (sell.size() > 0){
            res +=  sell.top()[1];
            res %= mod;
            sell.pop();
        }
        return res%mod;
    }
};