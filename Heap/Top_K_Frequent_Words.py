#Problem Link:- https://leetcode.com/problems/top-k-frequent-words/

"""Given a non-empty list of words, return the k most frequent elements.Your answer 
should be sorted by frequency from highest to lowest. If two words have the same 
frequency, then the word with the lower alphabetical order comes first."""

class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        import heapq
        d = dict()
        for i in range(len(words)):
            if words[i] not in d:
                d[words[i]] = 1
            else:
                d[words[i]] += 1
        heap = []
        for x in d:
            heappush(heap,(-d[x],x))
        ans = []
        for i in range(k):
            cnt,st = heappop(heap)
            ans.append(st)
        return ans
        
            