class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort()
        if not citations: return 0
        if len(citations) == 1: return int(bool(citations.pop()))
        i = 0
        j = len(citations) - 1
        while i < j:
            g = (i + j) >> 1
            if len(citations) - g > citations[g]:
                i = g + 1
            else:
                j = g
        return 0 if len(citations) - j > citations[j] else len(citations) - j 
        