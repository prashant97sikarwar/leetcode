class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        idx = 0
        leftsum = 0
        arrsum = sum(nums)
        while idx < len(nums):
            rightsum = arrsum - nums[idx]
            if leftsum == rightsum:
                return idx
            arrsum -= nums[idx]
            leftsum += nums[idx]
            idx += 1
        return -1