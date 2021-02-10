#Problem Link:- https://leetcode.com/problems/find-the-most-competitive-subsequence/

"""Given an integer array nums and a positive integer k, return the most competitive subsequence
of nums of size k.e define that a subsequence a is more competitive than a subsequence b (of the
same length) if in the first position where a and b differ, subsequence a has a number less than
the corresponding number in b."""

class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        stack = []
        for idx,val in enumerate(nums):
            remain = len(nums) - idx
            while stack and val < stack[-1] and len(stack) + remain > k:
                stack.pop()
            
            if len(stack) < k:
                stack.append(val)
        return stack