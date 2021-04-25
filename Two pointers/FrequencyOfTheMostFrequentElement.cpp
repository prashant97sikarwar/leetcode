//Problem Link;- https://leetcode.com/problems/frequency-of-the-most-frequent-element/

/*You are given an integer array nums and an integer k. In one operation, you can choose an 
index of nums and increment the element at that index by 1.Return the maximum possible frequency 
of an element after performing at most k operations.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        long ans = 1, sm = 0, left = 0;
        sort(begin(nums), end(nums));
        for(int i=0;i<n;i++){
            sm += nums[i];
            while ((i-left+1)*nums[i] - sm > k && left < n){
                sm -= nums[left++];
            }
            ans =  max(ans,i-left+1);
        }
        ans = max(ans,n-1-left+1);
        return ans;
    }
};
