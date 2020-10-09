# Problem Link :- https://leetcode.com/problems/generate-parentheses/
"""Given n pairs of parentheses, write a function to generate all combinations 
of well-formed parentheses."""

class Solution(object):
    def generateParenthesis(self, n):
        ans = []
        self.helper("",0,0,n,ans)
        return ans
        
        
    def helper(self,s,l,r,n,ans):
        if len(s) == 2 * n:
            ans.append(s)
            return 
        if l < n:
            self.helper(s+'(',l+1,r,n,ans)
        if r < l:
            self.helper(s+')',l,r+1,n,ans)
        