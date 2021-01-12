#Problem Link:- https://leetcode.com/problems/maximum-score-from-removing-substrings/

"""You are given a string s and two integers x and y. You can perform two types of 
operations any number of times.Remove substring "ab" and gain x points.For example, when 
removing "ab" from "cabxbae" it becomes "cxbae".Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".Return the maximum points
you can gain after applying the above operations on s."""

class Solution(object):
    def maximumGain(self, s, x, y):
        if x > y:
            res = 0
            st = []
            for i in range(len(s)):
                if len(st) > 0:
                    if st[-1] == 'a' and s[i] == 'b':
                        res += x
                        st.pop()
                        continue
                st.append(s[i])
            st4 = []
            for i in range(len(st)):
                if len(st4) > 0:
                    if st4[-1] == 'b' and st[i] == 'a':
                        res += y
                        st4.pop()
                        continue
                st4.append(st[i])
            return res
        else:
            res = 0
            st2 = []
            for i in range(len(s)):
                if len(st2) > 0:
                    if st2[-1] == 'b' and s[i] == 'a':
                        res += y
                        st2.pop()
                        continue
                st2.append(s[i])
            st3 = []
            for i in range(len(st2)):
                if len(st3) > 0:
                    if st3[-1] == 'a' and st2[i] == 'b':
                        res += x
                        st3.pop()
                        continue
                st3.append(st2[i])
            return res