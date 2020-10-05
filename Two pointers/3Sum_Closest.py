# Problem Link :- https://leetcode.com/problems/3sum-closest/

"""Given an array nums of n integers and an integer target, find three integers in 
nums such that the sum is closest to target. Return the sum of the three integers. 
You may assume that each input would have exactly one solution."""

class Solution(object):
    def threeSumClosest(self, nums, target):
        n = len(nums)
        x,y,z = -1,-1,-1
        nums.sort()
        if n <= 3:
            return sum(nums)
        diff = float('inf')
        for i in range(n):
            sm = target-nums[i]
            l = i+1
            r = n-1
            while l < r:
                temp = abs(sm - (nums[l]+nums[r]))
                if temp < diff:
                    diff = temp
                    x,y,z = i,l,r
                    if diff == 0:
                        return nums[x]+nums[y]+nums[z]
                if nums[l] + nums[r] < sm:
                    l += 1
                else:
                    r -= 1
        return nums[x]+nums[y]+nums[z]
                        
                