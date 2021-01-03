#Problem Link:- https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

"""Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' 
or ')', and in any positions ) so that the resulting parentheses string is valid.Formally, a 
parentheses string is valid if and only if:It is the empty string, orIt can be written as AB 
(A concatenated with B), where A and B are valid strings, or It can be written as (A), where 
A is a valid string.Given a parentheses string, return the minimum number of parentheses we 
must add to make the resulting string valid."""

class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        if len(s) == 0:
            return 0
        st = []
        ans = 0
        for x in s:
            if x is '(':
                st.append('(')
            elif x is ')':
                if len(st) > 0:
                    st.pop()
                else:
                    ans += 1
        return ans + len(st)