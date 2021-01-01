#Problem Link:- https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

"""Given an array of integers nums and an integer target.Return the number of non-empty 
subsequences of nums such that the sum of the minimum and maximum element on it is less 
or equal to target. Since the answer may be too large, return it modulo 109 + 7."""

class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        end = len(nums) -1
        mod = 1000000007
        nums.sort()
        res = 0
        for i in range(end+1):
            while nums[i] + nums[end] > target:
                if end > i:
                    end -= 1
                else:
                    return res % mod
            res += pow(2,end-i)
            res %= mod
        return res%mod