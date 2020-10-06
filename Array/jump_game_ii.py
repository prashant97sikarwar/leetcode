# Problem Link :- https://leetcode.com/problems/jump-game-ii/

"""Given an array of non-negative integers, you are initially positioned at the first 
index of the array.Each element in the array represents your maximum jump length at that 
position.Your goal is to reach the last index in the minimum number of jumps."""

class Solution(object):
    def jump(self, nums):
        n = len(nums)
        if n == 1:
            return 0
        max_position = [i+nums[i] for i in range(n)]
        cur_ind = 0
        cnt = 0
        while cur_ind < n-1:
            if cur_ind + nums[cur_ind] >= n-1:
                cnt += 1
                cur_ind = n-1
                break
            else:
                mx = 0
                for i in range(cur_ind+nums[cur_ind],cur_ind,-1):
                    if max_position[i] > mx:
                        mx = max_position[i]
                        cur_ind = i
                cnt += 1
        return cnt