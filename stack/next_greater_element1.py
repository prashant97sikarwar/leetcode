""" You are given two arrays (without duplicates) nums1 
and nums2 where nums1’s elements are subset of nums2. 
Find all the next greater numbers for nums1's elements 
in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the 
first greater number to its right in nums2. If it does 
not exist, output -1 for this number. """


class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        from collections import defaultdict
        d = {}
        d = defaultdict(lambda:-1,d)
        st = []
        for i in range(len(nums2)):
            while st and st[-1] < nums2[i]:
                d[st.pop()] = nums2[i]
            st.append(nums2[i])
        for i in range(len(nums1)):
            nums1[i] = d[nums1[i]]
        return nums1