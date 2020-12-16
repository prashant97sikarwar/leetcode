#Problem link:- https://leetcode.com/problems/friend-circles/

"""There are N students in a class. Some of them are friends, while some are not. Their 
friendship is transitive in nature. For example, if A is a direct friend of B, and B is a 
direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a 
group of students who are direct or indirect friends.Given a N*N matrix M representing the
friend relationship between students in the class. If M[i][j] = 1, then the ith and jth 
students are direct friends with each other, otherwise not. And you have to output the 
total number of friend circles among all the students."""

class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        parent = [-1 for i in range(len(M))]
        for i in range(len(M)):
            for j in range(len(M)):
                if M[i][j] == 1:
                    fir = self.find(i,parent)
                    sec = self.find(j,parent)
                    if fir != sec:
                        parent[fir] = sec
        cnt = 0
        for i in range(len(M)):
            if parent[i] == -1:
                cnt+=1
        return cnt
        
    def find(self,u,parent):
        if parent[u] == -1:
            return u
        parent[u] = self.find(parent[u],parent)
        return parent[u]