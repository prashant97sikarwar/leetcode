class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        l = 0
        h = len(nums)-1
        while l <= h:
            mid = l + (h-l)//2
            if nums[l] == target or nums[h] == target or nums[mid] == target:
                return True
            elif nums[mid] < nums[h]:
                if target > nums[mid] and target < nums[h]:
                    l = mid+1
                else:
                    h = mid-1
            elif nums[mid] > nums[l]:
                if target > nums[l] and target < nums[mid]:
                    h = mid-1
                else:
                    l = mid+1
            else:
                h -= 1
        if h == -1:
            return False
        return False
                