#Problem Link :- https://leetcode.com/problems/binary-tree-right-side-view/submissions/

"""Given a binary tree, imagine yourself standing on the right side of it, return the 
values of the nodes you can see ordered from top to bottom."""

## BFS approach

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class bfsSolution:
    def rightSideView(self, root):
        ans = []
        if root is None:
            return []
        else:
            que = []
            que.append(root)
            while que:
                count = len(que)
                while count > 0:
                    node = que.pop(0)
                    if node.left:
                        que.append(node.left)
                    if node.right:
                        que.append(node.right)
                    count -= 1
                ans.append(node.val)
        return ans
        
        
## DFS approach


class dfsSolution:
    def rightSideView(self, root):
        if root is None:
            return 
        d = {}
        def dfs(root,depth):
            if root is None:
                return 
            d[depth] = root.val
            dfs(root.left,depth+1)
            dfs(root.right,depth+1)
        dfs(root,0)
        return list(d.values())
        