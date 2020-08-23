"""Given two arrays, write a function to compute their intersection."""


class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        s = set(nums1)
        l = []
        for i in range(len(nums2)):
            if nums2[i] in s:
                l.append(nums2[i])
        return list(set(l))