//Problem Link:- https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m = nums2.size(),i = 0,j = 0;
        int res = 0;
        while (i < n && j < m){
            if (nums1[i] > nums2[j]){
                i++;
            }
            else if (i > j && nums1[i] <= nums2[j]){
                j++;
            }
            else if (i <= j && nums1[i] <= nums2[j]){
                res = max(res,j-i);
                j++;
            }
        }
        return res;
    }
};