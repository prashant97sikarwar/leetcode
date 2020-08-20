"""Given a binary tree root and a linked list with head as the first node. 
Return True if all the elements in the linked list starting from the head 
correspond to some downward path connected in the binary tree otherwise return False.
In this context downward path means a path that starts at some node and goes downwards."""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSubPath(self, head: ListNode, root: TreeNode) -> bool:
        target = ""
        while head:
            target += str(head.val)
            head = head.next
        return self.dfs(root,str(root.val),target)
    
    def dfs(self,root,path,target):
        if target in path:
            return True
        if root.left:
            left = self.dfs(root.left, path + str(root.left.val),target)
            if left == True:
                return True
        if root.right:
            right = self.dfs(root.right, path + str(root.right.val),target)
            if right == True:
                return True
        return False
        