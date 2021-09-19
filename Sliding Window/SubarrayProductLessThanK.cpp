//Problem Link:- https://leetcode.com/problems/subarray-product-less-than-k/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
        const int n = arr.size();
        int start = 0, end = 0;
        int count = 0, sum = arr[0];
        while (start < n && end < n) {
            if (sum < k) {
                end++;

                if (end >= start)
                    count += end - start;

                if (end < n)
                    sum *= arr[end];
            }
            else {
                sum /= arr[start];
                start++;
            }
        }

        return count;
    }
};