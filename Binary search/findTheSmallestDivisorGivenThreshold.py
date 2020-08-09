class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        import math
        l = 1
        r = max(nums)-1
        while l < r:
            mid = l + (r-l)//2
            if self.check(nums,mid) > threshold:
                l = mid + 1
            else:
                r = mid
        return l
            
            
    def check(self,nums,mid):
        sm = 0
        for i in range(len(nums)):
            dep = math.ceil(nums[i]/mid)
            sm += dep
        return sm