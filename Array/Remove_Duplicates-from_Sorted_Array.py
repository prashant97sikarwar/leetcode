# Problem link :- https://leetcode.com/problems/remove-duplicates-from-sorted-array/

"""Given a sorted array nums, remove the duplicates in-place such that each element appears 
only once and returns the new length.Do not allocate extra space for another array, you must 
do this by modifying the input array in-place with O(1) extra memory."""

class Solution:
    def removeDuplicates(self, nums):
        i = 1
        while i < len(nums):
            if nums[i] == nums[i-1]:
                nums.pop(i)
                i-=1
            i+=1
        return len(nums)