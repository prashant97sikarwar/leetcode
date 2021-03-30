//Problem Link:- https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

/* Given an integer array nums, return the maximum result of nums[i] XOR nums[j], 
where 0 ≤ i ≤ j < n.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& arr) {
        int maxx = 0, mask = 0;
  
        set<int> se;
        int n = arr.size();
        for (int i = 30; i >= 0; i--) {
            mask |= (1 << i);

            for (int i = 0; i < n; ++i) {
                se.insert(arr[i] & mask);
            }

            int newMaxx = maxx | (1 << i);

            for (int prefix : se) {
                if (se.count(newMaxx ^ prefix)) {
                    maxx = newMaxx;
                    break;
                }
            }
            se.clear();
        }

        return maxx;        
    }
};