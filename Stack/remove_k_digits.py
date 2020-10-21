# Problem link :- https://leetcode.com/problems/remove-k-digits/

"""Given a non-negative integer num represented as a string, remove k digits 
from the number so that the new number is the smallest possible."""

class Solution(object):
    def removeKdigits(self, num, k):
        if len(num) == 0:
            return 
        st = []
        for i in range(len(num)):
            while st and int(num[i]) < int(st[-1]) and k > 0:
                st.pop()
                k-= 1
                if k == 0:
                    break
            if len(st) == 0 and num[i] == "0":
                continue
            else:
                st.append(num[i])
        while k > 0 and st:
            st.pop()
            k -= 1
        if k >= 0 and len(st) == 0:
            return "0"
        return "".join(st)