class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        l,sm,size,r=0,0,inf,len(nums)
        for i in range(r):
            sm += nums[i]
            while l < r and sm >= s:
                size = min(size,i-l+1)
                sm -= nums[l]
                l += 1
        return size if size != inf else 0