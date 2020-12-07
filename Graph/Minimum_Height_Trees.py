#Problem link :- https://leetcode.com/problems/minimum-height-trees/
"""Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where 
edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai 
and bi in the tree, you can choose any node of the tree as the root. When you select a 
node x as the root, the result tree has height h. Among all possible rooted trees, those 
with minimum height (i.e. min(h))  are called minimum height trees (MHTs).Return a list 
of all MHTs' root labels. You can return the answer in any order."""

class Solution(object):
    def findMinHeightTrees(self, n, edges):
        if n <= 2:
            return [i for i in range(n)]
        from collections import defaultdict
        graph = defaultdict(list)
        deg = [0 for i in range(n)]
        for u,v in edges:
            graph[u].append(v)
            graph[v].append(u)
            deg[u] += 1
            deg[v] += 1
        que = []
        for i in range(n):
            if deg[i] == 1:
                que.append(i)
        while len(que) > 0:
            res = []
            rem = len(que)
            while rem > 0:
                rem -= 1
                node = que.pop(0)
                res.append(node)
                for x in graph[node]:
                    deg[x] -= 1
                    if deg[x] == 1:
                        que.append(x)
        return res
                        