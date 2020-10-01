"""Given a binary array, find the maximum length of a contiguous subarray 
with equal number of 0 and 1. """

class Solution(object):
    def findMaxLength(self, nums):
        d = dict()
        d[0] = 0
        count = 0
        l = 0
        for i in range(len(nums)):
            count += 1 if nums[i] == 1 else -1
            if count == 0:
                l = max(l,i+1)
            if count in d:
                l = max(l,i-d[count])
            else:
                d[count] = i
        return l
            
        