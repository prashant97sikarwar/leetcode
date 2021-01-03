#Problem Link:- https://leetcode.com/problems/remove-outermost-parentheses/

"""Given a valid parentheses string S, consider its primitive decomposition: S = P_1 + P_2 + 
+ P_k, where P_i are primitive valid parentheses strings.Return S after removing the 
outermost parentheses of every primitive string in the primitive decomposition of S."""

class Solution(object):
    def removeOuterParentheses(self, S):
        st = []
        ind = set()
        for i in range(len(S)):
            if S[i] == '(':
                st.append(i)
            if S[i] == ')':
                first = st.pop()
                if len(st) == 0:
                    ind.add(first)
                    ind.add(i)
                else:
                    continue
        res = ""
        for i in range(len(S)):
            if i in ind:
                continue
            else:
                res += S[i]
        return res