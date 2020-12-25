#Problem Link:- https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

"""You are given two integer arrays nums1 and nums2 sorted in ascending order and an 
integer k.Define a pair (u,v) which consists of one element from the first array and 
one element from the second array.Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with 
the smallest sums."""

class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        import heapq
        heap = []
        n = len(nums1)
        m = len(nums2)
        for i in range(n):
            for j in range(m):
                heappush(heap,(nums1[i] + nums2[j],(nums1[i],nums2[j])))
        ans = []
        for i in range(min(n*m,k)):
            sm,pair = heappop(heap)
            ans.append(pair)
        return ans