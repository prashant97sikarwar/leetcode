#Problem link:- https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

"""We are given a binary tree (with root node root), a target node, and an integer 
value K.Return a list of the values of all nodes that have a distance K from the 
target node.  The answer can be returned in any order."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, K: int):
        import collections
        def dfs(root,par=None):
            if root:
                root.par = par
                dfs(root.left,root)
                dfs(root.right,root)
        dfs(root)
        queue = collections.deque([(target,0)])
        visited = {target}
        while queue:
            if queue[0][1] == K:
                return [node.val for node,d in queue]
            node,d = queue.popleft()
            for nei in (node.left,node.right,node.par):
                if nei and nei not in visited:
                    visited.add(nei)
                    queue.append((nei,d+1))
        return []