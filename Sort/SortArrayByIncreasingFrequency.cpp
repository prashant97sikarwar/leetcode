//Problem Link:- https://leetcode.com/problems/sort-array-by-increasing-frequency/

/*Given an array of integers nums, sort the array in increasing order based on the frequency of 
the values. If multiple values have the same frequency, sort them in decreasing order.return the 
sorted array*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b){
    if (a.second == b.second){
        return a.first > b.first;
    }
    return a.second < b.second;
}
    
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> ump;
        for (auto num : nums) ump[num]++;
        vector<pair<int,int>> vct;
        for(auto x  : ump){
            vct.push_back(x);
        }
        sort(vct.begin(),vct.end(),cmp);
        vector<int> res{};
        for(auto x:vct){
            while (x.second--){
                res.push_back(x.first);
            }
        }
        return res;
    }
};