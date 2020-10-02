"""Given an array of integers and an integer k, you need to find 
the total number of continuous subarrays whose sum equals to k."""

class Solution(object):
    def subarraySum(self, nums, k):
        res =0 
        d = dict()
        sm = 0
        d[0] = 1
        for i in range(len(nums)):
            sm += nums[i]
            if sm-k in d:
                res += d[sm-k]
            if sm in d:
                d[sm] += 1
            else:
                d[sm] = 1
        return res 