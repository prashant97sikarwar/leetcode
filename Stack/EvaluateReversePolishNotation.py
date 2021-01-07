#Problem Link:- https://leetcode.com/problems/evaluate-reverse-polish-notation/

"""Evaluate the value of an arithmetic expression in Reverse Polish Notation.Valid 
operators are +, -, *, /. Each operand may be an integer or another expression."""

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st = []
        s = set(['+', '-', '*', '/'])
        n = len(tokens)
        for i in range(n):
            if tokens[i] in s:
                 first = st.pop()
                 sec = st.pop()
                 if tokens[i] == '+':
                    st.append(sec + first)
                 elif tokens[i] == '-':
                    st.append(sec - first)
                 elif  tokens[i] == '/':
                    st.append(int(sec/first))
                 elif tokens[i] == '*':
                    st.append(sec * first)
            else:
                 st.append(int(tokens[i]))
        return st[-1]