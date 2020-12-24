#Problem Link: https://leetcode.com/problems/top-k-frequent-elements/

"""Given a non-empty array of integers, return the k most frequent elements."""

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        import heapq
        d = {}
        ans = []
        n = len(nums)
        for i in range(n):
            if nums[i] not in d:
                d[nums[i]] = 1
            else:
                d[nums[i]] += 1
        heap = []
        for x in d:
            heapq.heappush(heap,(-d[x],x))
        for i in range(k):
            freq,num = heapq.heappop(heap)
            ans.append(num)
        return ans