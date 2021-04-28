//Problem Link:- https://leetcode.com/problems/arithmetic-subarrays/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        vector<bool> result;
        for(int i=0;i<m;i++){
            int left = l[i];
            int right = r[i];
            if (right-left+1 < 2){
                result.push_back(false);
                continue;
            }
            vector<int> temp;
            for(int i=left;i<=right;i++){
                temp.push_back(nums[i]);
            }
            sort(temp.begin(),temp.end());
            int k = temp[1] - temp[0];
            bool flag = false;
            for(int i=1;i<right-left+1;i++){
                if  (temp[i]-temp[i-1] != k){
                    flag = true;
                    result.push_back(false);
                    break;
                }
            }
            if (flag == false){
                result.push_back(true);
            }
        }
        return result;
    }
};