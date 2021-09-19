#Problem Link:- https://leetcode.com/problems/compare-version-numbers/

class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        first = version1.split(".")
        sec = version2.split(".")
        n = min(len(first), len(sec))
        for i in range(n):
            if int(first[i]) > int(sec[i]):
                return 1
        
            elif int(first[i]) < int(sec[i]):
                return -1
        n = len(first)
        m = len(sec)
        if (n > m):
            for i in range(m,n):
                if (int(first[i]) > 0):
                    return 1
        if (m > n):
            for i in range(n,m):
                if int(sec[i]) > 0:
                    return -1
        return 0