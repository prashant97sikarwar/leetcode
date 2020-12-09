#Problem Link :- https://leetcode.com/problems/similar-string-groups/

"""Two strings X and Y are similar if we can swap two letters (in different positions) of 
X, so that it equals Y. Also two strings X and Y are similar if they are equal.Together, 
these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.
We are given a list strs of strings where every string in strs is an anagram of every 
other string in strs. How many groups are there?"""

class Solution(object):
    def numSimilarGroups(self, strs):
        parent = [-1 for i in range(len(strs)+1)]
        check = []
        for i in range(len(strs)):
            for j in range(i+1,len(strs)):
                if (self.helper(strs[i],strs[j]) == True):
                    check.append((i+1,j+1))
        for u,v in check:
            self.union(u,v,parent)
        count = 0
        for i in range(1,len(parent)):
            if parent[i] == -1:
                count += 1
        return count
    
    
    def find(self,x,parent):
        if parent[x] == -1:
            return x
        return self.find(parent[x],parent)
    
    def union(self,x,y,parent):
        a = self.find(x,parent)
        b = self.find(y,parent)
        if a == b:
            return 
        parent[a] = b
        
    def helper(self,str1,str2):
        n = len(str1)
        cnt = 0
        if n == 1:
            return True
        i = 0
        while i < n:
            if str1[i] != str2[i]:
                cnt+=1
            i+=1
        if cnt == 0 or cnt == 2:
            return True
        return False
