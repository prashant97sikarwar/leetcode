#Problem Link:- https://leetcode.com/problems/ways-to-make-a-fair-array/

"""You are given an integer array nums. You can choose exactly one index (0-indexed) and remove 
the element.An array is fair if the sum of the odd-indexed values equals the sum of the even-
indexed values.Return the number of indices that you could choose such that after the removal, 
nums is fair. """

class Solution(object):
    def waysToMakeFair(self, nums):
        n = len(nums)
        even_sm = [0] * (n+1)
        odd_sm = [0] * (n+1)
        for i in range(n):
            if i % 2:
                odd_sm[i+1] = odd_sm[i] + nums[i]
                even_sm[i+1] = even_sm[i]
            else:
                odd_sm[i+1] = odd_sm[i]
                even_sm[i+1] = even_sm[i] + nums[i]
        ans = 0
        for i in range(1,n+1):
            odd = odd_sm[i-1]
            even = even_sm[i-1]
            after_odd = even_sm[-1] - even_sm[i]
            after_even = odd_sm[-1] - odd_sm[i]
            if odd + after_odd == even + after_even:
                ans += 1
        return ans