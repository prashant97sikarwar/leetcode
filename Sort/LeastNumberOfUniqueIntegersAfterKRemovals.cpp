//Problem Link:- https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

/*Given an array of integers arr and an integer k. Find the least number of unique integers 
after removing exactly k elements.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<int> freq;
        for(auto x : mp){
            freq.push_back(x.second);
        }
        sort(freq.begin(),freq.end());
        int res = freq.size();
        for(int i=0;i<freq.size();i++){
            if (freq[i] <= k){
                k -= freq[i];
                res--;
                if (k == 0){
                    break;
                }
            }
            else{
                break;
            }
        }
        return res;
    }
};