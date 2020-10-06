# Problem Link :- https://leetcode.com/problems/4sum/

"""Given an array nums of n integers and an integer target, are there elements a, b, c, and 
d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which 
gives the sum of target.Notice that the solution set must not contain duplicate quadruplets."""

class Solution(object):
    def fourSum(self, nums, target):
        n = len(nums)
        if n <= 3:
            return 
        nums.sort()
        ans = []
        for i in range(n-3):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            if nums[i]*4 > target:
                break
            for j in range(i+1,n-2):
                if j > i+1 and nums[j] == nums[j-1]:
                    continue
                if nums[j]*3 > target-nums[i]:
                    break
                l = j+1
                r = n-1
                while l < r:
                    data = nums[i] + nums[j] + nums[l] + nums[r]
                    if data == target:
                        ans.append([nums[i],nums[j],nums[l],nums[r]])
                        while l < r and nums[l] == nums[l+1]:
                            l += 1
                        while l < r and nums[r] == nums[r-1]:
                            r -= 1
                        l += 1
                        r -= 1
                    elif nums[i] + nums[j] + nums[l] + nums[r] < target:
                        l += 1
                    else:
                        r -= 1
        return ans