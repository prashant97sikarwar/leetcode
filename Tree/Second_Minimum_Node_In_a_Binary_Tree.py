# Problem link :- https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

"""Given a non-empty special binary tree consisting of nodes with the non-negative value, 
where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, 
then this node's value is the smaller value among its two sub-nodes. More formally, the property 
root.val = min(root.left.val, root.right.val) always holds.Given such a binary tree, you need to 
output the second minimum value in the set made of all the nodes' value in the whole tree."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findSecondMinimumValue(self, root):
        def dfs(root):
            if root:
                uniques.add(root.val)
                dfs(root.left)
                dfs(root.right)
        uniques = set()
        dfs(root)
        min1, ans = root.val, float('inf')
        for x in uniques:
            if min1 < x < ans:
                ans = x
        return ans if ans < float('inf') else -1