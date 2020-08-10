class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l = self.left(nums,target)
        r = self.right(nums,target)
        return [l,r]
        
    def right(self,nums,target):
        l = 0
        r = len(nums)-1
        right_ind = -1
        while l <= r:
            mid = l + (r-l)//2
            if nums[mid] == target:
                right_ind = max(mid,right_ind)
                l = mid+1
            elif nums[mid] < target:
                l = mid+1
            elif nums[mid] > target:
                r = mid-1
        return right_ind
    
    def left(self,nums,target):
        left_ind = inf
        l = 0
        r = len(nums) - 1
        while l <= r:
            mid = l + (r-l)//2
            if nums[mid] == target:
                left_ind = min(left_ind,mid)
                r = mid-1
            elif nums[mid] > target:
                r = mid-1
            elif nums[mid] < target:
                l = mid + 1
        return left_ind if left_ind != inf else -1
                
        