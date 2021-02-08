#Problem Link:- https://leetcode.com/problems/house-robber-ii/

"""You are a professional robber planning to rob houses along a street. Each house has a certain
amount of money stashed. All houses at this place are arranged in a circle. That means the first
house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected,
and it will automatically contact the police if two adjacent houses were broken into on the same
night.Given a list of non-negative integers nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the police."""

class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 2:
            return max(nums[0],nums[1])
        if len(nums) == 3:
            return max(nums[0],nums[1],nums[2])
        n = len(nums)
        dp1 = [0 for i in range(len(nums))]
        dp2 = [0 for i in range(len(nums))]
        dp1[0] = nums[0]
        dp1[1] = max(nums[0],nums[1]) 
        dp2[1] = nums[1]
        dp2[2] = max(nums[1],nums[2])
        for i in range(2,n-1):
            dp1[i] = max(nums[i] + dp1[i-2],dp1[i-1])
        for i in range(3,n):
            dp2[i] = max(nums[i] + dp2[i-2],dp2[i-1])
        return max(dp1[n-2], dp2[n-1])