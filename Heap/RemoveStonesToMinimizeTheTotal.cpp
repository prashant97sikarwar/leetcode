//Problem Link:- https://leetcode.com/problems/remove-stones-to-minimize-the-total/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        const int n = piles.size();
        int total = accumulate(piles.begin(),piles.end(),0);
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(piles[i]);
        }
        int  res = 0;
        while (k--){
            int node = pq.top();
            pq.pop();
            res += node/2;
            node = node - (node/2);
            pq.push(node);
        }
        return total - res;
    }
    
};