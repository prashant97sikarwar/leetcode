#Problem Link;- https://leetcode.com/problems/fraction-to-recurring-decimal/

class Solution:
    def fractionToDecimal(self, num: int, den: int) -> str:
        if num == 0:
	        return "0"
        sign = -1 if ((num < 0) ^ (den < 0)) else 1
        res = []
        if sign == -1:
            res.append("-")
        num = abs(num)
        den = abs(den)
        initial = num // den
        res.append(str(initial))
        d = dict()
        rem = num % den
        if rem > 0:
            res.append(".")
        repeat = False
        while  (rem > 0 and not repeat):
            if rem in d:
                repeat = True
                idx = d[rem]
                break
            else:
                d[rem] = len(res)
            rem *= 10
            temp = rem // den
            res.append(str(temp))
            rem %= den
        if repeat:
            res.append(")")
            res.insert(idx,"(")
        return "".join(res)

        