#Problem Link :- https://leetcode.com/problems/add-one-row-to-tree/

"""Given the root of a binary tree, then value v and depth d, you need to add a row 
of nodes with value v at the given depth d. The root node is at depth 1"""

##BFS iterative approach

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class bFSSolution:
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:
        if d == 1:
            node = TreeNode(v)
            node.left = root
            return node
        else:
            que = [root]
            depth = 1
            while que:
                count = len(que)
                while count > 0:
                    if depth == d-1:
                        while que:
                            temp = que.pop(0)
                            leftptr = temp.left
                            rightptr = temp.right
                            node1 = TreeNode(v)
                            node2 = TreeNode(v)
                            temp.left = node1
                            temp.right = node2
                            node1.left = leftptr
                            node2.right = rightptr
                        return root
                    else:
                        temp = que.pop(0)
                        if temp.left:
                            que.append(temp.left)
                        if temp.right:
                            que.append(temp.right)
                    count -= 1
                depth += 1
            return root

## recursive solution

class RecurSolution:
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:
        if d == 1:
            node = TreeNode(v)
            node.left = root
            return node
        self.helper(root,v,1,d)
        return root
    
    def helper(self,root,v,depth,d):
        if root is None:
            return 
        if depth == d-1:
            leftptr = root.left
            node1 = TreeNode(v)
            root.left = node1
            root.left.left = leftptr
            rightptr = root.right
            node2 = TreeNode(v)
            root.right = node2
            root.right.right = rightptr
        else:
            self.helper(root.left,v,depth+1,d)
            self.helper(root.right,v,depth+1,d)
            
             
                    
                    