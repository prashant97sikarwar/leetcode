# Problem Link :- https://leetcode.com/problems/3sum/
"""Given an array nums of n integers, are there elements a, b, c in nums such that 
a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Notice that the solution set must not contain duplicate triplets."""

class Solution(object):
    def threeSum(self, nums):
        target = 0
        n = len(nums)
        nums.sort()
        ans = []
        if n <= 2:
            return 
        for i in range(n):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            if nums[i]*3 > target:
                break
            l = i+1
            r = n -1
            while l < r:
                data = nums[i] + nums[l] + nums[r]
                if data == target:
                    ans.append([nums[i],nums[l],nums[r]])
                    while l < r and nums[l] == nums[l+1]:
                        l += 1
                    while l < r and nums[r] == nums[r-1]:
                        r -= 1
                    l += 1
                    r -= 1
                elif data < target:
                    l += 1
                else:
                    r -= 1
        return ans