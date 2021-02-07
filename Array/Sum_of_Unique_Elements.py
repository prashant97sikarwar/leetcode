#Problem Link:- https://leetcode.com/contest/biweekly-contest-45/problems/sum-of-unique-elements/

"""You are given an integer array nums. The unique elements of an array are the elements 
that appear exactly once in the array.Return the sum of all the unique elements of nums."""

class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        sm = 0
        n = len(nums)
        d = dict()
        for i in range(n):
            if nums[i] not in d:
                d[nums[i]] = 1
            else:
                d[nums[i]] += 1
        for x in d:
            if d[x] == 1:
                sm += x
        return sm