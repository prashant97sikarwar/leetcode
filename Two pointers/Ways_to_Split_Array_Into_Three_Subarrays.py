#Problem Link:- https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/

"""A split of an integer array is good if:The array is split into three non-empty 
contiguous subarrays - named left, mid, right respectively from left to right.The sum of 
the elements in left is less than or equal to the sum of the elements in mid, and the sum 
of the elements in mid is less than or equal to the sum of the elements in right.Given 
nums, an array of non-negative integers, return the number of good ways to split nums. 
As the number may be too large, return it modulo 109 + 7."""

class Solution(object):
    def waysToSplit(self, nums):
        mod = 1000000007
        prefix =[0]
        
        for i in range(len(nums)):
            prefix.append(prefix[-1]+nums[i])
        res  = 0
        for i in range(1,len(nums)):
            l = bisect_left(prefix,2*prefix[i])
            r = bisect_right(prefix,(prefix[-1]+prefix[i])//2)
            res += max(0, min(len(nums), r)-max(i+1, l))
        return res%mod