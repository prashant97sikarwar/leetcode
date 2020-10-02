"""Given an integer array, you need to find one continuous subarray that 
if you only sort this subarray in ascending order, then the whole array 
will be sorted in ascending order, too.You need to find the shortest such 
subarray and output its length."""

class Solution(object):
    def findUnsortedSubarray(self, nums):
        n = len(nums)
        l = n
        r = 0
        if n <= 1:
            return 0
        st = []
        for i in range(n):
            while st and nums[st[-1]] > nums[i]:
                l = min(l,st.pop())
            st.append(i)
        st = []
        for i in range(n-1,-1,-1):
            while st and nums[st[-1]] < nums[i]:
                r = max(r,st.pop())
            st.append(i)
        return r-l+1 if r-l > 0 else 0