#Problem Link :- https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

"""Given two binary search trees root1 and root2.Return a list containing all the 
integers from both trees sorted in ascending order."""

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def getAllElements(self, root1, root2):
        if root1 is None and root2 is None:
            return 
        ans1 = self.inorder(root1,[])
        ans2 = self.inorder(root2,[])
        if not root1:
            return ans2
        if not root2:
            return ans1
        res = []
        n = len(ans1)
        m = len(ans2)
        i = 0
        j = 0
        while i < n and j < m:
            if ans1[i] <= ans2[j]:
                res.append(ans1[i])
                i += 1
            else:
                res.append(ans2[j])
                j += 1
        while i < n:
            res.append(ans1[i])
            i += 1
        while j < m:
            res.append(ans2[j])
            j += 1
        return res
        
        
        
    def inorder(self,root,first):
        if root is None:
            return 
        self.inorder(root.left,first)
        first.append(root.val)
        self.inorder(root.right,first)
        return first
        