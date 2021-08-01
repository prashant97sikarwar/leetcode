//Problem Link:- https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        const int n = arr.size();
        int mx = -1;
        vector<int> result(n,0);
        for(int i=n-1;i>=0;i--){
            result[i] = mx;
            mx = max(mx,arr[i]);
        }
        return result;
    }
};