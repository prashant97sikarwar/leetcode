# Problem Link :- https://leetcode.com/problems/combination-sum/

"""Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations 
of candidates where the chosen numbers sum to target. You may return the combinations in any 
order.The same number may be chosen from candidates an unlimited number of times. Two 
combinations are unique if the frequency of at least one of the chosen numbers is different.
It is guaranteed that the number of unique combinations that sum up to target is less than 
150 combinations for the given input."""

class Solution(object):
    def combinationSum(self, candidates, target):
        ans = []
        return self.helper(candidates,target,ans,0)
        
    
    def helper(self,candidates,target,ans,ind):
        if target < 0:
            return []
        elif target == 0:
            return [[]]
        elif ind == len(candidates):
            return []
        cuNum = candidates[ind]
        ans = self.helper(candidates,target,ans,ind+1)
        other = self.helper(candidates,target-cuNum,ans,ind)
        for x in other:
            x.append(cuNum)
            ans.append(x)
        return ans
            