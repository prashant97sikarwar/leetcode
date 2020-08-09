class Solution:
    def findMin(self, nums: List[int]) -> int:
        l  = 0
        r = len(nums)-1
        while l < r:
            mid = l + (r-l)//2
            if nums[mid] > nums[mid+1]:
                return nums[mid + 1]
            if nums[mid] < nums[mid+1] and nums[mid] < nums[mid-1]:
                return nums[mid]
            elif nums[mid] > nums[mid-1] and nums[mid] < nums[mid+1] and nums[mid] > nums[0]:
                l = mid + 1
            elif nums[mid] > nums[mid-1] and nums[mid] < nums[mid+1] and nums[mid] < nums[0]:
                r = mid - 1
        return nums[0]
                