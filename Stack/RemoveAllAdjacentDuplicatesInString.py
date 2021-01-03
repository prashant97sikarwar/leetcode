#Problem Link:- https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

"""Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent
and equal letters, and removing them.We repeatedly make duplicate removals on S until we no 
longer can.Return the final string after all such duplicate removals have been made.  It is 
guaranteed the answer is unique."""

class Solution(object):
    def removeDuplicates(self, S):
        st = ['0']
        for x in S:
            if st[-1] == x:
                while st[-1] == x:
                    st.pop()
            else:
                st.append(x)
        st.pop(0)
        return "".join(st)