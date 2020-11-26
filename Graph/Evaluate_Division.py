#Problem Link:- https://leetcode.com/problems/evaluate-division/

"""you are given an array of variable pairs equations and an array of real numbers values, 
where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each 
Ai or Bi is a string that represents a single variable.You are also given some queries, where 
queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.
Return the answers to all queries. If a single answer cannot be determined, return -1.0."""

class Solution(object):
    def calcEquation(self, equations, values, queries):
        from collections import defaultdict
        graph = defaultdict(dict)
        for (i,j),val in zip(equations,values):
            graph[i][j] = val
            graph[j][i] = 1.0/val
        res = []
        
        def dfs(x,y,visited):
            if x not in graph or y not in graph:
                return -1.0
            if y in graph[x]:
                return graph[x][y]
            
            for i in graph[x]:
                if i not in visited:
                    visited.add(i)
                    temp = dfs(i, y, visited)
                    if temp == -1:
                        continue
                    else:
                        return graph[x][i] * temp
            return -1
        for query in queries:
            res.append(dfs(query[0], query[1], set()))
        return res
