#Problem Link:- https://leetcode.com/problems/shortest-path-with-alternating-colors/

"""Consider a directed graph, with nodes labelled 0, 1, ..., n-1.  In this graph, each 
edge is either red or blue, and there could be self-edges or parallel edges.Each [i, j] 
in red_edges denotes a red directed edge from node i to node j.  Similarly, each [i, j] 
in blue_edges denotes a blue directed edge from node i to node j.Return an array answer 
of length n, where each answer[X] is the length of the shortest path from node 0 to node 
X such that the edge colors alternate along the path (or -1 if such a path doesn't exist).
"""

class Solution:
    def shortestAlternatingPaths(self, n: int, red_edges: List[List[int]], blue_edges: List[List[int]]) -> List[int]:
        if n == 0:
            return []
        
        adjList = {i:[] for i in range(n)}
        for start, end in red_edges:
            adjList[start].append((end, 'r'))
        for start, end in blue_edges:
            adjList[start].append((end, 'b'))
        ans = [-1] * n
        ans[0] = 0
        stack = []
        for nextPtr, color in adjList[0]:
            stack.append((nextPtr, color))
        visited = {(0, 'r'), (0, 'b')}
        level = 0
        while stack :
            level +=1 
            nextStack = []
            for node,color in stack:
                if ans[node] == -1:
                    ans[node] = level
                else:
                    ans[node] = min(level,ans[node])
                for nextPtr, nextColor in adjList[node]:
                    if nextColor != color and (nextPtr,nextColor) not in visited:
                        nextStack.append((nextPtr, nextColor))
                        visited.add((nextPtr, nextColor))
            stack = nextStack
        return ans