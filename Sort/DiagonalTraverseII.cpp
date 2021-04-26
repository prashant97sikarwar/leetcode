//Problem Link:- https://leetcode.com/problems/diagonal-traverse-ii/

/*Given a list of lists of integers, nums, return all elements of nums in diagonal order as shown 
in the below images.*/

#include<bits/stdc++.h>
using namespace std;

bool cmp(tuple<int,int,int> a,tuple<int,int,int> b){
    if (get<0>(a) < get<0>(b) ){
        return true;
    }
    else if (get<0>(a) > get<0>(b)){
        return false;
    }
    else{
        if (get<1>(a) < get<1> (b)){
            return false;
        }
        return true;
    }
}

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<tuple<int,int,int>> arr;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                int sm = i+j;
                arr.push_back(make_tuple(sm,i,nums[i][j]));
            }
        }
        sort(arr.begin(),arr.end(),cmp);
        vector<int> result;
        for(int i=0;i<arr.size();i++){
            result.push_back(get<2> (arr[i]));
        }
        return result;
    }
};