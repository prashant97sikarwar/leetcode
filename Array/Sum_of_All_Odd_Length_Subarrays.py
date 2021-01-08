#Problem Link:- https://leetcode.com/problems/sum-of-all-odd-length-subarrays/

"""Given an array of positive integers arr, calculate the sum of all possible odd-length 
subarrays.A subarray is a contiguous subsequence of the array.Return the sum of all odd-
length subarrays of arr."""

class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        sm = 0
        prefix_sm = [0 for i in range(len(arr))]
        prefix_sm[0] = arr[0]
        for i in range(1,len(arr)):
            prefix_sm[i] = prefix_sm[i-1] + arr[i]
        for i in range(len(arr)):
            sm += arr[i]
        for i in range(len(arr)):
            for j in range(i+1,len(arr)):
                if (j-i+1) % 2 == 1:
                    sm += prefix_sm[j] - prefix_sm[i] + arr[i]
        return sm