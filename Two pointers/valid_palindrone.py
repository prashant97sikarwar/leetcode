"""Given a string, determine if it is a palindrome, considering only 
alphanumeric characters and ignoring cases.
Note: For the purpose of this problem, we define empty string as valid palindrome."""

class Solution(object):
    def isPalindrome(self, s):
        lst = [letter.lower() for letter in s if letter.isalnum()]
        if lst == lst[::-1]:
            return True
        return False