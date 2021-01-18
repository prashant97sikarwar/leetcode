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
    
## binary search concept
    
class binarySearch_solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        if len(nums) == 0:return 0
        if len(nums) == 1:
            return 1 if nums[0] >= s else 0
        ans = float("inf")
        
        def helper(nums,s,ind):
            l = 0
            sm = 0
            for i in range(len(nums)):
                sm += nums[i]
                while l < len(nums) and i-l+1 > ind:
                    sm -= nums[l]
                    l += 1
                if sm >= s:
                    return True
            return False
        
        left = 1
        right = len(nums)
        while left <= right:
            mid = left + (right - left) // 2
            if helper(nums,s,mid) == True:
                ans = min(ans,mid)
                right = mid - 1
            else:
                left = mid + 1
        
        return ans if ans != float("inf") else 0