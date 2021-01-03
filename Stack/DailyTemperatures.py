#Problem Link:- https://leetcode.com/problems/daily-temperatures/

"""Given a list of daily temperatures T, return a list such that, for each day in the input, 
tells you how many days you would have to wait until a warmer temperature. If there is no 
future day for which this is possible, put 0 instead. """

class Solution(object):
    def dailyTemperatures(self, T):
        n = len(T)
        st = [n-1]
        ans = [0]
        for i in range(n-2,-1,-1):
            while st and T[st[-1]] <= T[i]:
                st.pop()
                if len(st) == 0:
                    ans.append(0)
            if st and T[st[-1]] > T[i]:
                ans.append(st[-1]-i)
            st.append(i)
        return ans[::-1]