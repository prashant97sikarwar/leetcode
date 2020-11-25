#Problem Link :- https://leetcode.com/problems/find-eventual-safe-states/

"""In a directed graph, we start at some node and every turn, walk along a directed edge of 
the graph.  If we reach a node that is terminal (that is, it has no outgoing directed edges), 
we stop.Now, say our starting node is eventually safe if and only if we must eventually walk 
to a terminal node.  More specifically, there exists a natural number K so that for any 
choice of where to walk, we must have stopped at a terminal node in less than K steps.
Which nodes are eventually safe?  Return them as an array in sorted order"""

class Solution(object):
    def eventualSafeNodes(self, graph):
        ans = []
        n = len(graph)
        cycle = [False for i in range(n)]
        safe = [False for i in range(n)]
        visited = [False for i in range(n)]
        def helper(cur,graph,visited):
            if safe[cur] == True:
                return True
            if cycle[cur] == True:
                return False
            if visited[cur] == True:
                cycle[cur] = True
                return False
            visited[cur] = True
            for x in graph[cur]:
                if helper(x,graph,visited) == False:
                    cycle[x] = True
                    return False
            safe[cur] = True
            return True
        for i in range(len(graph)):
            if helper(i,graph,visited):
                ans.append(i)
        return ans