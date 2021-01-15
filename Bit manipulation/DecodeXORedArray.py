#Problem Link:- https://leetcode.com/problems/decode-xored-array/

"""There is a hidden integer array arr that consists of n non-negative integers.It was 
encoded into another integer array encoded of length n - 1, such that encoded[i] = arr[i] 
XOR arr[i + 1].Return the original array arr. It can be proved that the answer exists and 
is unique."""

class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        n = len(encoded) + 1
        ans = [first]
        for i in range(n-1):
            nxt = ans[-1] ^ encoded[i]
            ans.append(nxt)
        return ans