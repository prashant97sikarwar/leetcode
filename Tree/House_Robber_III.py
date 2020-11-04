# Problem link :- https://leetcode.com/problems/house-robber-iii/

"""The thief has found himself a new place for his thievery again. There is only one 
entrance to this area, called the "root." Besides the root, each house has one and only 
one parent house. After a tour, the smart thief realized that "all houses in this place 
forms a binary tree". It will automatically contact the police if two directly-linked 
houses were broken into on the same night.Determine the maximum amount of money the 
thief can rob tonight without alerting the police."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rob(self, root: TreeNode) -> int:
        def helper(root):
            if not root:
                return (0,0)
            left = helper(root.left)
            right = helper(root.right)
            rob = root.val + left[1] + right[1]
            not_rob = max(left) + max(right)
            
            return [rob,not_rob]
        return max(helper(root))