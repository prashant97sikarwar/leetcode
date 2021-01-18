#Problem Link:- https://leetcode.com/problems/string-compression/

"""Given an array of characters chars, compress it using the following algorithm:Begin with an 
empty string s. For each group of consecutive repeating characters in chars:If the group's 
length is 1, append the character to s.Otherwise, append the character followed by the group's 
length.The compressed string s should not be returned separately, but instead be stored in the 
input character array chars. Note that group lengths that are 10 or longer will be split into 
multiple characters in chars.After you are done modifying the input array, return the new 
length of the array."""

class Solution:
    def compress(self, chars: List[str]) -> int:
        if not chars:
            return 0
        
        curr, count, ind = chars[0], 1, 1
        while ind < len(chars):
            if chars[ind] == curr:
                count += 1
                chars.pop(ind)
            
            elif chars[ind] != curr:
                if count != 1:
                    for i in str(count):
                        chars.insert(ind, i)
                        ind += 1

                curr,count = chars[ind], 1
                ind += 1
        
        if count > 1:
            for i in str(count):
                chars.append(i)
        
        return len(chars)
