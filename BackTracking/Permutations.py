# Problem Link :- https://leetcode.com/problems/permutations/
'''Given a collection of distinct integers, return all possible permutations.'''

class Solution(object):
    def permute(self, nums):
        n = len(nums)
        if n == 1:
            return [nums]
        res = []
        def helper(arr,path):
            if len(arr) == 2:
                res.append(path+arr)
                res.append(path+arr[::-1])
            for i in range(len(arr)):
                helper([num for num in arr if num != arr[i]], path + [arr[i]])
        helper(nums,[])
        return res


        