# Problem Link :- https://leetcode.com/problems/combination-sum-ii/

"""Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.
Each number in candidates may only be used once in the combination."""

class Solution(object):
    def combinationSum2(self, candidates, target):
        ans = []
        candidates.sort()
        return self.helper(candidates,target,ans,[],0)
        
    def helper(self,nums,target,ans,path,ind):
        if target < 0:
            return 
        elif target == 0:
            if path not in ans:
                ans.append(path)
                return 
        for i in range(ind,len(nums)):
            self.helper(nums,target-nums[i],ans,path+[nums[i]],i+1)
        return ans
        