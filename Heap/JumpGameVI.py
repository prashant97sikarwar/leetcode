#Problem Link:- https://leetcode.com/problems/jump-game-vi/

"""You are given a 0-indexed integer array nums and an integer k.You are initially 
standing at index 0. In one move, you can jump at most k steps forward without going 
outside the boundaries of the array. That is, you can jump from index i to any index
in the range [i + 1, min(n - 1, i + k)] inclusive.You want to reach the last index of 
the array (index n - 1). Your score is the sum of all nums[j] for each index j you 
visited in the array.Return the maximum score you can get."""

class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        n = len(nums)
        deq = deque()
        deq.append(0)
        dp = [0] * n
        dp[0] = nums[0]
        for i in range(1, n):
            dp[i] = nums[i] + dp[deq[0]]   
            if deq[0] < i - k + 1:
                deq.popleft()              
            while deq and dp[deq[-1]] < dp[i]:         
                deq.pop()                   
            deq.append(i)
        return dp[-1]     