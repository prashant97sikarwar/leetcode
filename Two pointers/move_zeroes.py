"""Given an array nums, write a function to move all 0's to the end 
of it while maintaining the relative order of the non-zero elements."""


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        index = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[index] = nums[i]
                index += 1
        for i in range(index,len(nums)):
            nums[i] = 0
        