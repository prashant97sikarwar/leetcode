#Problem Link:- https://leetcode.com/problems/max-consecutive-ones-iii/

"""Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
Return the length of the longest (contiguous) subarray that contains only 1s."""

class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        n = len(A)
        cnt0 = 0
        left = 0
        size = -1
        for i in range(n):
            if A[i] == 0:
                cnt0 += 1
            while(cnt0 > K and left < n):
                if A[left] == 0:
                    cnt0 -= 1
                left += 1
            size = max(size,i-left+1)
        if size == -1:
            if cnt0 <= k:
                return n
            else:
                return 0
        else:
            return size