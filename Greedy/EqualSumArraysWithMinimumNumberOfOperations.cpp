//Problem Link:- https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int first = accumulate(nums1.begin(), nums1.end(),0);
        int sec = accumulate(nums2.begin(), nums2.end(),0);
        vector<int> arr1;
        vector<int> arr2;
        if (first == sec)
            return 0;
        if (sec > first){
            arr1 = nums2;
            arr2 = nums1;
        }
        else{
            arr1 = nums1;
            arr2 = nums2;
        }
        cout <<arr1.size() << endl;
        priority_queue<int> pq;
        for(int i=0;i<arr1.size();i++){
            pq.push(arr1[i]-1);
        }
        for(int i=0;i<arr2.size();i++){
            pq.push(6-arr2[i]);
        }
        int cnt = 0;
        int val;
        int diff = abs(first - sec);
        while (pq.size() > 0 && diff > 0){
            val = pq.top();
            pq.pop();
            diff -= val;
            cnt++;
        } 
        if (diff > 0)
            return -1;
        return cnt;
    }
};