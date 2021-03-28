#Problem Link:- https://leetcode.com/problems/number-of-different-integers-in-a-string/

"""You are given a string word that consists of digits and lowercase English letters.
You will replace every non-digit character with a space.Return the number of different 
integers after performing the replacement operations on word."""

class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        s = set()
        lt = ""
        for i in range(len(word)):
            if (word[i].isdigit()):
                lt+=word[i]
            else:
                if len(lt) > 0:
                    lt = lt.lstrip('0')
                    s.add(lt)
                lt = ""
        lt = lt.lstrip('0')
        if len(lt) > 0:
            s.add(lt)
        return len(s)