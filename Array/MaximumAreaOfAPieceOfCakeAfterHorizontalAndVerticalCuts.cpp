//Problem Link:- https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;
    int maxArea(int h, int w, vector<int>& nums1, vector<int>& nums2) {
        int horimax = 0;
        int vertimax = 0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(int i=0;i<nums1.size();i++){
            int diff = (i == 0 ? nums1[i] : nums1[i]-nums1[i-1]);
            horimax = max(horimax, diff);
        }
        horimax = max(horimax, h - nums1.back())%mod;
        for(int i=0;i<nums2.size();i++){
            int diff = (i == 0 ? nums2[i] : nums2[i]-nums2[i-1]);
            vertimax = max(vertimax, diff);
        }
        vertimax = max(vertimax, w - nums2.back())%mod;
        return ((1LL*vertimax%mod)*(horimax%mod))%mod;
    }
};