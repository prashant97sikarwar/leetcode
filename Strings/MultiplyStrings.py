#Problem Link:- https://leetcode.com/problems/multiply-strings/

class Solution(object):
    def add(self,num1,num2):
        res = ""
        i = len(num1) - 1
        j = len(num2) - 1
        carry = 0
        while i >= 0 and j >= 0:
            sm = int(num1[i]) + int(num2[j]) + carry
            carry = sm / 10
            dg = sm % 10
            res = str(dg) + res
            i -= 1
            j -= 1
        while (i >= 0):
            sm = carry + int(num1[i])
            carry = sm / 10
            dg = sm % 10
            res = str(dg) + res
            i -= 1
        while (j >= 0):
            sm = carry + int(num2[j])
            carry = sm / 10
            dg = sm % 10
            res = str(dg) + res
            j -= 1
        if (carry > 0):
            res = str(carry) + res
        return res
    def multiply(self, num1, num2):
        if (len(num1) == 1 and num1[0] == "0"):
            return "0"
        if (len(num2) == 1 and num2[0] == "0"):
            return "0"
        num1.lstrip('0')
        num2.lstrip('0')
        res = self.mul(num1,num2[len(num2)-1])
        for i in range(len(num2)-2,-1,-1):
            ans = self.mul(num1,num2[i])
            ans += ((len(num2)-i-1)*'0')
            res = self.add(res,ans)
        return res
            
        
    def mul(self,num1,char):
        res = ""
        carry = 0
        for i in range(len(num1)-1,-1,-1):
            prd = int(char) * int(num1[i]) + carry
            carry = prd / 10
            dg = prd % 10
            res = str(dg) + res
        if (carry > 0):
            res = str(carry) + res
        return res
        
        