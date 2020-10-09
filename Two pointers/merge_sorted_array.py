# Problem Link :- https://leetcode.com/problems/merge-sorted-array/
"""Given two sorted integer arrays nums1 and nums2, 
merge nums2 into nums1 as one sorted array."""

class Solution(object):
    def merge(self, nums1, m, nums2, n):
        i, j = m - 1, n - 1
        pos = m + n - 1
        while i >= 0 and j >= 0:
            if nums1[i] > nums2[j]:
                nums1[pos] = nums1[i]
                i -= 1
            else:
                nums1[pos] = nums2[j]
                j -= 1
            pos -= 1
        if i == -1:
            nums1[:j+1] = nums2[:j+1]