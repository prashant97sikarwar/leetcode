#Problem Link:- https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/

"""You are given two arrays of integers nums1 and nums2, possibly of different lengths. The values 
in the arrays are between 1 and 6, inclusive.In one operation, you can change any integer's value 
in any of the arrays to any value between 1 and 6, inclusive.Return the minimum number of operations 
required to make the sum of values in nums1 equal to the sum of values in nums2. Return -1​​​​​ if it is 
not possible to make the sum of the two arrays equal."""

class Solution(object):
    def minOperations(self, nums1, nums2):
        import heapq
        first = sum(nums1)
        sec = sum(nums2)
        if sec == first:
            return 0
        if sec > first:
            nums1,nums2 = nums2,nums1
            first,sec = sec,first
        heap = []
        for i in range(len(nums1)):
            heappush(heap,-(nums1[i] - 1))
        for i in range(len(nums2)):
            heappush(heap,-(6 - nums2[i]))
        diff = abs(first-sec)
        cnt = 0
        while heap and diff > 0:
            val = -heappop(heap)
            diff -= val
            cnt += 1
        if diff > 0:
            return -1
        return cnt