"""Write a function that takes a string as input 
and reverse only the vowels of a string."""

class Solution:
    def reverseVowels(self, s: str) -> str:
        s = list(s)
        i = 0
        dr = set(['a','e','i','o','u','A','E','I','O','U'])
        j = len(s) - 1
        while i <= j:
            if s[i] in dr and s[j] in dr:
                s[i], s[j] = s[j], s[i]
                i += 1
                j -= 1
            elif s[i] in dr and s[j] not in dr:
                j -= 1
            elif s[i] not in dr and s[j] in dr:
                i += 1
            else:
                i += 1
                j -= 1
        return ''.join(s)