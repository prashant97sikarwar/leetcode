#Problem Link :- https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

"""Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is 
said to be pseudo-palindromic if at least one permutation of the node values in the path is a 
palindrome.Return the number of pseudo-palindromic paths going from the root node to leaf nodes."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def pseudoPalindromicPaths (self, root: TreeNode) -> int:
        arr = [0 for i in range(10)]
        return self.dfs(root,arr)
        
    def dfs(self,root,arr):
        if not root:
            return 0
        if not root.left and not root.right:
            cnt = 0
            arr[root.val] += 1
            for x in arr:
                if x % 2==1:
                    cnt += 1
            arr[root.val] -= 1
            if cnt <= 1:
                return 1
            else:
                return 0
        else:
            arr[root.val] += 1
            ans = self.dfs(root.left,arr) + self.dfs(root.right,arr)
            arr[root.val] -= 1
            return ans