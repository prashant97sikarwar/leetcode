#Problem Link:- https://leetcode.com/contest/weekly-contest-216/problems/check-if-two-string-arrays-are-equivalent/

"""Given two string arrays word1 and word2, return true if the two arrays represent the same 
string, and false otherwise.A string is represented by an array if the array elements 
concatenated in order forms the string."""

class Solution(object):
    def arrayStringsAreEqual(self, word1, word2):
        first = "".join(word1)
        sec = "".join(word2)
        if first == sec:
            return True
        return False