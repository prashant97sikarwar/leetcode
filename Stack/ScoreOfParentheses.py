#Problem link:- https://leetcode.com/problems/score-of-parentheses/

"""Given a balanced parentheses string S, compute the score of the string based on the 
following rule:
-> () has score 1
-> AB has score A + B, where A and B are balanced parentheses strings.
-> (A) has score 2 * A, where A is a balanced parentheses string."""

class Solution(object):
    def scoreOfParentheses(self, s):
        n = len(s)
        
        def helper(l,r):
            ans = 0
            res = 0
            for i in range(l,r):
                ans += 1 if s[i] == '(' else  -1
                if ans == 0:
                    if i-l == 1:
                        res += 1
                    else:
                        res += 2*helper(l+1,i)
                    l = i+1
            return res
        return helper(0,n)