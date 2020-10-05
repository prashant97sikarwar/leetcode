# Problem Link :- https://leetcode.com/problems/k-diff-pairs-in-an-array/

"""Given an array of integers nums and an integer k, return the number of unique 
k-diff pairs in the array.A k-diff pair is an integer pair (nums[i], nums[j]), 
where the following are true:
0 <= i, j < nums.length
i != j
a <= b
b - a == k"""

class Solution(object):
    def findPairs(self, nums, k):
        ans = 0
        d =  dict()
        n = len(nums)
        for i in range(n):
            if nums[i] not in d:
                d[nums[i]] = 1
            else:
                d[nums[i]] += 1
        for x in d:
            if k == 0 and d[x+k] >= 2:
                ans += 1
            elif k != 0 and x+k not in d:
                continue
            elif k != 0 and x+k in d:
                ans += 1
        return ans