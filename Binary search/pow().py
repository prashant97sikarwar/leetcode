class Solution:
    def myPow(self, x: float, n: int) -> float:
        b = abs(n)
        res = 1
        while b > 0:
            if (b & 1):
                res *= x
                b -= 1
            else:
                x *= x
                b >>=1
        return res if n >= 0 else 1/res
        