#Problem Link:- https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

"""Given a string s of '(' , ')' and lowercase English characters. Your task is to remove 
the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting 
parentheses string is valid and return any valid string."""

class Solution(object):
    def minRemoveToMakeValid(self, s):
        st = []
        ind = set()
        for i in range(len(s)):
            if s[i] != ')':
                st.append(i)
            else:
                if len(st) > 0:
                    while st and s[st[-1]] != '(':
                        st.pop()
                    if len(st) == 0:
                        ind.add(i)
                    else:
                        st.pop()
                else:
                    ind.add(i)
        while st:
            check = st.pop()
            if s[check] == '(':
                ind.add(check)
        res = ""
        for i in range(len(s)):
            if i not in ind:
                res += s[i]
        return res