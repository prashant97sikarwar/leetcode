# Problem Link :- https://leetcode.com/problems/subsets/

"""Given a set of distinct integers, nums, return all possible subsets (the power set)."""

class Solution(object):
    def subsets(self, nums):
        p = len(nums)-1
        n = 1 << len(nums)
        ans = []
        for i  in range(n):
            l = []
            for j in range(p+1):
                if i & (1 << j):
                    l.append(nums[p-j])
                else:
                    continue
            ans.append(l)
        return ans
                