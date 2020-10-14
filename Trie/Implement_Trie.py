# Problem Link :- https://leetcode.com/problems/implement-trie-prefix-tree/

"""Implement a trie with insert, search, and startsWith methods."""

class TrieNode:
    def __init__(self):
        self.childNodes = {}
        self.isWordEnd = False

class Trie(object):

    def __init__(self):
        self.root = TrieNode()
        

    def insert(self, word):
        currNode = self.root
        for ch in word:
            node = currNode.childNodes.get(ch , TrieNode())
            currNode.childNodes[ch] = node
            currNode = node
        currNode.isWordEnd = True
        
        

    def search(self, word):
        currNode = self.root
        for ch in word:
            node = currNode.childNodes.get(ch)
            if  not node:
                return False
            currNode = node

        return currNode.isWordEnd
        

    def startsWith(self, prefix):
        currNode = self.root
        for ch in prefix:
            node = currNode.childNodes.get(ch)
            if not node:
                return False
            currNode = node

        return True
        


