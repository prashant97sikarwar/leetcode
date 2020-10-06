# Problem Link :- https://leetcode.com/problems/search-insert-position/

"""Given a sorted array of distinct integers and a target value, return the index 
if the target is found. If not, return the index where it would be if it were inserted 
in order."""

class Solution:
    def searchInsert(self, nums, target):
        l = 0
        r  = len(nums) - 1
        return self.bsearch(nums,l,r,target)
        
        
    def bsearch(self,nums,l,r,target):
        if l <= r:
            mid = l + (r-l)//2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                return self.bsearch(nums,mid+1,r,target)
            else:
                return self.bsearch(nums,l,mid-1,target)
        else:
            return r +1
                
            
    
    
    