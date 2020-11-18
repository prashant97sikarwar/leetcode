#Problem Link:- https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

"""Given a binary tree root. Split the binary tree into two subtrees by removing 1 
edge such that the product of the sums of the subtrees are maximized.Since the answer 
may be too large, return it modulo 10^9 + 7."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxProduct(self, root: TreeNode) -> int:
        if root is None:
            return 0
        s = set()
        def helper(root):
            if root is None:
                return 0
            currSum = root.val + helper(root.left) + helper(root.right)
            s.add(currSum)
            return currSum
        helper(root)
        ans = -1
        total = self.Sum(root)
        arr = list(s)
        for i in range(len(arr)):
            ans = max(ans,(total - arr[i])*arr[i])
        return ans%1000000007
        
    def Sum(self,root):
        if root is None:
            return 0
        else:
            return root.val + self.Sum(root.left) + self.Sum(root.right)