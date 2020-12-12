#Problem Link:- https://leetcode.com/problems/word-ladder/

"""Given two words (beginWord and endWord), and a dictionary's word list, find the length 
of shortest transformation sequence from beginWord to endWord, such that:Only one letter 
can be changed at a time.Each transformed word must exist in the word list."""

class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        if not wordList: return 0
        memory = {}
        for word in wordList:
            for i in range(len(word)):
                key = word[:i] + "*" + word[i+1:]
                memory.setdefault(key, []).append(word)
        visited = set()
        visited.add(beginWord)
        frontier = [beginWord]
        level = 1
        while frontier:
            _next = []
            for word in frontier:
                # find neighbors
                neighbors = []
                for i in range(len(word)):
                    key = word[:i] + '*' + word[i+1:]
                    neighbors += memory.get(key, [])
                # explore the neighbors
                for neighbor in neighbors:
                    # match? we are done here
                    if neighbor == endWord: return level+1
                    if neighbor not in visited:
                        _next.append(neighbor)
                        visited.add(neighbor)
            level += 1
            frontier = _next
        return 0