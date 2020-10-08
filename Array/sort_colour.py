# Problem Link :- https://leetcode.com/problems/sort-colors/

"""Sort the array consists of only numbers 0,1 and 2."""

class Solution(object):
    def sortColors(self, nums):
        l = 0
        r = len(nums)-1
        i = 0
        while i <= r:
            if nums[i] == 0:
                nums[l],nums[i] = nums[i],nums[l]
                l += 1
                i += 1
            elif nums[i] == 1:
                i += 1
            elif nums[i] == 2:
                nums[i],nums[r] = nums[r],nums[i]
                r -= 1
        return nums