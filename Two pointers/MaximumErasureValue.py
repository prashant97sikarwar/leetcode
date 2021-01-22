#Problem Link:- https://leetcode.com/problems/maximum-erasure-value/

"""You are given an array of positive integers nums and want to erase a subarray containing 
unique elements. The score you get by erasing the subarray is equal to the sum of its elements.
Return the maximum score you can get by erasing exactly one subarray."""

class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        s = set()
        sm = 0
        ans = 0
        left = 0
        for i in range(len(nums)):
            if nums[i] not in s:
                sm += nums[i]
                s.add(nums[i])
            else:
                ans = max(ans,sm)
                while nums[i] in s:
                    s.discard(nums[left])
                    sm -= nums[left]
                    left += 1
                sm += nums[i]
                s.add(nums[i])
        ans = max(ans,sm)
        return ans
        