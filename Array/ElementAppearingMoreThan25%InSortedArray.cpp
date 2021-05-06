//Problem Link:- https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        float cnt = 0.25*arr.size();
        for(int i=0;i<arr.size();i++){
            if (mp[arr[i]] > cnt){
                return arr[i];
            }
        }
        return 0;
    }
};