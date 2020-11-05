# Problem Link:- https://leetcode.com/problems/serialize-and-deserialize-bst/

"""Design an algorithm to serialize and deserialize a binary search tree."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:

    def serialize(self, root: TreeNode) -> str:
        def dfs(root, string):
            if root is None:
                string += 'None,'
            else:
                string += str(root.val) + ','
                string = dfs(root.left, string)
                string = dfs(root.right, string)
            return string
        return dfs(root, '')
    

    def deserialize(self, data: str) -> TreeNode:
        def dfs(l):
            if(l[0] == "None"):
                l.pop(0)
                return None
            root = TreeNode( l.pop(0) )
            root.left = dfs(l)
            root.right = dfs(l)
            return root
        return dfs( data.split(",")[:-1] )
        

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans