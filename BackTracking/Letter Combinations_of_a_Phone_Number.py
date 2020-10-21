#Problem Link:- https://leetcode.com/problems/letter-combinations-of-a-phone-number/

"""Given a string containing digits from 2-9 inclusive, return all possible letter 
combinations that the number could represent. Return the answer in any order.A mapping 
of digit to letters (just like on the telephone buttons) is given below. Note that 1 does 
not map to any letters."""

class Solution(object):
    def letterCombinations(self, digits):
        result = []
        if len(digits) == 0:
            return result
        string = ["0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
        self.helper(result,digits,"",0,string)
        return result
    
    def helper(self,result,digits,current,index,string):
        if index == len(digits):
            result.append(current)
            return
        letters = string[int(digits[index])]
        for i in range(len(letters)):
            self.helper(result,digits,current+letters[i],index+1,string)
        return result