# problem Link :- https://leetcode.com/problems/jump-game/

"""Given an array of non-negative integers, you are initially positioned at the first 
index of the array.Each element in the array represents your maximum jump length at that 
position.Determine if you are able to reach the last index."""

class Solution(object):
    def canJump(self, nums):
        n = len(nums)
        position = [i+nums[i] for i in range(n)]
        check = n-1
        for i in range(n-2,-1,-1):
            if position[i] >= check:
                check = i
        if check == 0:
            return True
        return False
            