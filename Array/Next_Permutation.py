# Problemv Link :- https://leetcode.com/problems/next-permutation/

"""Implement next permutation, which rearranges numbers into the lexicographically next greater 
permutation of numbers.If such an arrangement is not possible, it must rearrange it as the 
lowest possible order (i.e., sorted in ascending order).The replacement must be in place and 
use only constant extra memory."""

class Solution(object):
    def nextPermutation(self, nums):
        i = len(nums) - 2
        while i >= 0 and nums[i] >= nums[i+1]:
            i -= 1
        if i >= 0:
            j = len(nums)-1
            while j >= 0 and nums[j] <= nums[i]:
                j -= 1
            nums[i],nums[j] = nums[j],nums[i]
        self.reverse(nums,i+1)
        
            
    def reverse(self,arr,ind):
        i = ind
        j = len(arr) - 1
        while i < j:
            arr[i],arr[j] = arr[j],arr[i]
            i += 1
            j -= 1
        