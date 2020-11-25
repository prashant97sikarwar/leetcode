#Problem Link:- https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
"""Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array 
edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.
Find the smallest set of vertices from which all nodes in the graph are reachable. It's 
guaranteed that a unique solution exists."""

class Solution(object):
    def findSmallestSetOfVertices(self, n, edges):
        visited = [False for i in range(n)]
        for i in range(len(edges)):
            if visited[edges[i][1]] == False:
                visited[edges[i][1]] = True
        ans =[]
        for i in range(n):
            if visited[i] == False:
                ans.append(i)
        return ans