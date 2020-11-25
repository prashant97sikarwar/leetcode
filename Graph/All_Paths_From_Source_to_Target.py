#Problem link;- https://leetcode.com/problems/all-paths-from-source-to-target/
"""Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all 
possible paths from node 0 to node n - 1, and return them in any order.the graph is given 
as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a 
directed edge from node i to node graph[i][j])."""

class Solution(object):
    def allPathsSourceTarget(self, graph):
        self.graph = graph
        self.answer = []
        
        def dfs(nodes, prev_nodes):
            for i in range(len(nodes)):
                node = nodes[i]
                if node == len(self.graph) - 1:
                    self.answer.append(prev_nodes + [node])
                dfs(self.graph[node], prev_nodes + [node])
        
        dfs(graph[0], [0])
        return self.answer
    