# Problem Link :- https://leetcode.com/problems/median-of-two-sorted-arrays/

"""Given two sorted arrays nums1 and nums2 of size m and n respectively, 
return the median of the two sorted arrays."""

class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        m = len(nums1)
        n = len(nums2)
        arr = [0]*(m+n)
        i = 0
        j = 0
        k = 0
        while i < m and j < n:
            if nums1[i] <= nums2[j]:
                arr[k] = nums1[i]
                i += 1
            else:
                arr[k] = nums2[j]
                j += 1
            k += 1
        while i < m:
            arr[k] = nums1[i]
            i += 1
            k += 1
        while j < n:
            arr[k] = nums2[j]
            j += 1
            k += 1
        l = m+n
        if l%2 == 1:
            return arr[((l+1)//2)-1]
        else:
            return ((arr[(l//2)-1]) + (arr[(l//2)]))/2