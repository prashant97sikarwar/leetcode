#Problem Link:- https://leetcode.com/problems/satisfiability-of-equality-equations/

"""Given an array equations of strings that represent relationships between variables, 
each string equations[i] has length 4 and takes one of two different forms: "a==b" or 
"a!=b".  Here, a and b are lowercase letters (not necessarily different) that represent 
one-letter variable names.Return true if and only if it is possible to assign integers 
to variable names so as to satisfy all the given equations."""

class Solution(object):
    def equationsPossible(self, equations):
        parent = [-1 for i in range(26)]
        check = []
        for i in range(len(equations)):
            a = equations[i][0]
            b = equations[i][3]
            if equations[i][1] == '=':
                self.union(ord(a)-ord('a'),ord(b)-ord('a'),parent)
            else:
                check.append((ord(a)-ord('a'),ord(b)-ord('a')))
        for i in range(len(check)):
            a = check[i][0]
            b = check[i][1]
            fir = self.find(a,parent)
            sec = self.find(b,parent)
            if fir == sec:
                return False
        return True
        
        

    def union(self,a,b,parent):
        if a == b:
            return 
        p = self.find(a,parent)
        q = self.find(b,parent)
        if p == q:
            return 
        parent[p] = q
    
    def find(self,a,parent):
        if parent[a] == -1:
            return a
        return self.find(parent[a],parent)
            