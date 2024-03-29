#Problem Link:- https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

"""Given an array of integers nums and an integer limit, return the size of the longest non-empty 
subarray such that the absolute difference between any two elements of this subarray is less than 
or equal to limit."""

class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        mx, mn = collections.deque([0]), collections.deque([0])
        ans = 1
        left = 0
        for i in range(1, len(nums)):
            while mx and nums[mx[-1]] < nums[i]:
                mx.pop()
            mx.append(i)
            while mn and nums[mn[-1]] > nums[i]:
                mn.pop()
            mn.append(i)
            while mx and mn and nums[mx[0]] - nums[mn[0]] > limit:
                left += 1
                if mx[0] < left:
                    mx.popleft()
                if mn[0] < left:
                    mn.popleft()
            ans = max(ans, i-left+1)
        return ans
