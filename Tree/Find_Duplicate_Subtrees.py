# Problem Link:- https://leetcode.com/problems/find-duplicate-subtrees/

"""Given the root of a binary tree, return all duplicate subtrees.For each kind of 
duplicate subtrees, you only need to return the root node of any one of them.Two 
trees are duplicate if they have the same structure with the same node values."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findDuplicateSubtrees(self, root: TreeNode):
        from collections import defaultdict
        
        if not root:
            return None
        
        res = []
        subtrees = defaultdict(int)
        
        def divide_and_conquer(node):
            if not node:
                return "#"
            
            left = divide_and_conquer(node.left)
            right = divide_and_conquer(node.right)
            tree = "{},{},{}".format(node.val, left, right)
            if subtrees[tree] == 1:
                res.append(node)
            subtrees[tree] += 1
            return tree
        

        divide_and_conquer(root)
        
        return res