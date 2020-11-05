# problem Link :- https://leetcode.com/problems/most-frequent-subtree-sum/

"""Given the root of a tree, you are asked to find the most frequent subtree sum. The 
subtree sum of a node is defined as the sum of all the node values formed by the subtree 
rooted at that node (including the node itself). So what is the most frequent subtree sum 
value? If there is a tie, return all the values with the highest frequency in any order."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findFrequentTreeSum(self, root: TreeNode):
        if root is None:
            return 
        d = dict()
        def subsetSum(root):
            if root is None:
                return 0
            curr_sum = root.val + subsetSum(root.left) + subsetSum(root.right)
            if curr_sum not in d:
                d[curr_sum] = 1
            else:
                d[curr_sum] += 1
            return curr_sum
        subsetSum(root)
        check = max(d.values())
        ans = []
        for x in d:
            if d[x] == check:
                ans.append(x)
        return ans