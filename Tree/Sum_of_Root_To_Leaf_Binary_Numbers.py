# Problem Link :- https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

"""You are given the root of a binary tree where each node has a value 0 or 1.  Each 
root-to-leaf path represents a binary number starting with the most significant bit.  
For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in 
binary, which is 13.For all leaves in the tree, consider the numbers represented by the 
path from the root to that leaf.Return the sum of these numbers. The answer is guaranteed 
to fit in a 32-bits integer."""

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def sumRootToLeaf(self, root):
        total = [0]
        def helper(root,current,total):
            if root is None:
                return 0
            current = 2 * current + root.val
            if root.left is None and root.right is None:
                total[0] += current
            helper(root.left,current,total)
            helper(root.right,current,total)
        helper(root,0,total)
        return total[0]
            