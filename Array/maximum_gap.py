"""Given an unsorted array, find the maximum difference between the successive 
elements in its sorted form.Return 0 if the array contains less than 2 elements."""


class Solution(object):
    def maximumGap(self, nums):
        n = len(nums)
        if n < 2:
            return 0
        nums.sort()
        mx = -1
        for i in range(n-1):
            mx = max(mx,nums[i+1]-nums[i])
        return mx
