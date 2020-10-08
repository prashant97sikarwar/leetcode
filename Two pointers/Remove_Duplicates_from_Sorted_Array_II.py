# Problem Link :- https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

"""Given a sorted array nums, remove the duplicates in-place such that duplicates 
appeared at most twice and return the new length.Do not allocate extra space for 
another array, you must do this by modifying the input array in-place with O(1) 
extra memory."""

class Solution(object):
    def removeDuplicates(self, nums):
        n = len(nums)
        if n <= 2:
            return n
        i = 1
        last = nums[0]
        cnt = 0
        while i < n:
            if nums[i] == last:
                if cnt == 1:
                    nums.pop(i)
                    n -= 1
                elif cnt < 1:
                    cnt += 1
                    i += 1
            else:
                last = nums[i]
                cnt = 0
                i += 1
            