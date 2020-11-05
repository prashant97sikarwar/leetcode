#Problem Link:- https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

"""Design an algorithm to serialize and deserialize a binary tree. """

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:
    def serialhelp(self,root,path):
        if root is None:
            path.append("None")
            return
        else:
            path.append(str(root.val))
            self.serialhelp(root.left,path)
            self.serialhelp(root.right,path)
            
    def help2(self,data):
        if data[0] == "None":
            data.pop(0)
            return
        else:
            node = TreeNode(data[0])
            data.pop(0)
            node.left = self.help2(data)
            node.right = self.help2(data)
        return node
    
    def serialize(self, root):
        path = []
        if root is None:
            return []
        else:
            self.serialhelp(root,path)
            path = ','.join(path)
        return path
        

    def deserialize(self, data):
        if not data:
            return
        else:
            data = data.split(',')
            return self.help2(data)
            
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))