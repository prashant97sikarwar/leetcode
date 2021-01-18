#Problem Link:- https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

"""Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.
If there is no non-empty subarray with sum at least K, return -1."""

class Solution:
    def shortestSubarray(self, arr: List[int], k: int) -> int:
        s = collections.deque()    # Inc    # (sum, ind)
        curr = 0
        ans = float("inf")
        for i in range(len(arr)):
            curr += arr[i]
            if curr>=k: ans=min(ans, i+1)
            while s and curr - s[0][0]>=k:
                ans = min(ans, i-s.popleft()[1])
            while s and s[-1][0]>curr:
                s.pop()
            s.append((curr, i))
        
        return ans if ans!=float('inf') else -1
        