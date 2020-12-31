#Problem Link:- https://leetcode.com/problems/sliding-window-maximum/

"""You are given an array of integers nums, there is a sliding window of size k which is moving 
from the very left of the array to the very right. You can only see the k numbers in the window. 
Each time the sliding window moves right by one position.Return the max sliding window."""

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        mx = collections.deque([0])
        if len(nums) == 1:
            return [nums[0]]
        if k == 1:
            return nums
        ans = []
        left = 0
        for i in range(1,len(nums)):
            while mx and nums[mx[-1]] < nums[i]:
                mx.pop()
            mx.append(i)
            while mx and i-left+1 >= k:
                ans.append(nums[mx[0]])
                left += 1
                if mx[0] < left:
                    mx.popleft()
        return ans
