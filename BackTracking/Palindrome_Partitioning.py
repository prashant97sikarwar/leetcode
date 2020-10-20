# Problem Link :- https://leetcode.com/problems/palindrome-partitioning/
"""Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s."""

class Solution(object):
    def partition(self, s):
        ans =[]
        
        def helper(cur,res):
            if  len(cur) == 0:
                ans.append(res)
            
            for i in range(len(cur)):
                temp = cur[:i+1]
                if self.ispal(temp):
                    helper(cur[i+1:],res+[temp])
        helper(s,[])
        return ans
                    
    def ispal(self,s):
        if s == s[::-1]:
            return True
        return False