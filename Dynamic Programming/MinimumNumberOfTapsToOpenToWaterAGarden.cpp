//Problem Link:- https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> prefix(n+1,0);
        for(int i=0;i<ranges.size();i++){
            int left = max(i-ranges[i], 0);
            int right = min(i+ranges[i],n);
            prefix[left] = max(prefix[left],right);
        }
        int key = prefix[n];
        bool flag = false;
        for(int i=n-1;i>=0;i--){
            if (prefix[i] >= key){
                key = i;
                if (key == 0){
                    flag = true;
                    break;
                }
            }
        }
        if (flag  ==  false){
            return -1;
        }
        int num_fountains = 1;
        int right = prefix[0], next_right = 0;
        for (int i = 0; i <= n; i++) {
            if (i > right) {
                num_fountains++;
                right = next_right;
            }
            next_right = max(next_right, prefix[i]);
        }
        return num_fountains;
    }
};