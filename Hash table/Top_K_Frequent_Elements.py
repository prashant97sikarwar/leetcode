# Problem Link :- https://leetcode.com/problems/top-k-frequent-elements/
"""Given a non-empty array of integers, return the k most frequent elements."""

class Solution(object):
    def topKFrequent(self, nums, k):
        d = dict()
        for i in range(len(nums)):
            if nums[i] not in d:
                d[nums[i]] = 1
            else:
                d[nums[i]] += 1
        ans = []
        d = sorted(d,key=lambda x:d[x],reverse=True)
        for x in d:
            ans.append(x)
            k -= 1
            if k == 0:
                return ans
        return ans