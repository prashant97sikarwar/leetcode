# Problem Link :- https://leetcode.com/problems/plus-one/

"""Given a non-empty array of digits representing a non-negative integer, 
increment one to the integer.The digits are stored such that the most 
significant digit is at the head of the list, and each element in the 
array contains a single digit.You may assume the integer does not contain 
any leading zero, except the number 0 itself."""


class Solution(object):
    def plusOne(self, digits):
        dep = 1
        n = len(digits)
        sm = dep + digits[n-1]
        if sm <= 9:
            digits[n-1] = sm
        else:
            sam = 1
            digits[n-1] = 0
            for i in range(n-2,-1,-1):
                df = sam + digits[i]
                if df < 10:
                    digits[i] = df
                    sam = 0
                    break
                else:
                    digits[i] = 0
            if sam == 1:
                digits.insert(0,1)
        return digits