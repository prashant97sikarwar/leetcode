#Problem Link:- https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

"""Given a binary tree, return the vertical order traversal of its nodes values.
If two nodes have the same position, then the value of the node that is reported 
first is the value that is smaller.Return an list of non-empty reports in order 
of X coordinate.  Every report will have a list of values of nodes."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def verticalTraversal(self, root: TreeNode):
        if root is None:
            return 
        from collections import defaultdict
        d = defaultdict(list)
        def helper(root,width,depth):
            if root is None:
                return 
            d[width].append((depth,root.val))
            helper(root.left,width-1,depth+1)
            helper(root.right,width+1,depth+1)
        helper(root,0,0)
        return [[v[1] for v in sorted(d[k])] for k in sorted(d)] 