#Problem Link:- https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

"""You are given a string s that consists of lower case English letters and brackets. 
Reverse the strings in each pair of matching parentheses, starting from the innermost one.
Your result should not contain any brackets."""

class Solution(object):
    def reverseParentheses(self, s):
        st = []
        que = []
        for i in range(len(s)):
            if s[i] == ')':
                while st[-1] != '(':
                    que.append(st.pop())
                st.pop()
                while len(que) > 0:
                    st.append(que.pop(0))
            else:
                st.append(s[i])
        return "".join(st)