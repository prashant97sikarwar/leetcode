#Problem Link:- https://leetcode.com/problems/find-the-town-judge/

"""In a town, there are N people labelled from 1 to N.  There is a rumor that one 
of these people is secretly the town judge.If the town judge exists, then:The town 
judge trusts nobody.Everybody trusts the town judge.There is exactly one person 
that satisfies properties 1 and 2.If the town judge exists and can be identified, 
return the label of the town judge.  Otherwise, return -1."""

class Solution:
    def findJudge(self, N: int, trust):
        if len(trust) < N-1:
            return -1
        s = [0] * (N+1)
        for i,j in trust:
                s[i] -= 1
                s[j] += 1
        for i in range(1,N+1):
            if s[i] == N-1:
                return i
        return -1
