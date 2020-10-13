# Problem Link:- https://leetcode.com/problems/kth-largest-element-in-an-array/

"""Find the kth largest element in an unsorted array. Note that it is the 
kth largest element in the sorted order, not the kth distinct element."""

class Solution(object):
    def findKthLargest(self, nums, k):
        import heapq
        heap = []
        for x in nums:
            if len(heap) < k:
                heapq.heappush(heap,x)
            elif x > heap[0]:
                heapq.heapreplace(heap,x)
        return heapq.heappop(heap)