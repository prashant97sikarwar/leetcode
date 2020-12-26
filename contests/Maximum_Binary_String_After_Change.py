#Problem Link:- 

"""ou are given a binary string binary consisting of only 0's or 1's. You can apply each 
of the following operations any number of times:Operation 1: If the number contains the 
substring "00", you can replace it with "10".For example, "00010" -> "10010"Operation 2: 
If the number contains the substring "10", you can replace it with "01".For example, 
"00010" -> "00001"Return the maximum binary string you can obtain after any number of 
operations. Binary string x is greater than binary string y if x's decimal representation
is greater than y's decimal representation."""

class Solution:
    def maximumBinaryString(self, binary: str) -> str:
        if len(binary) < 2:
            return binary
        if len(binary) == 2:
            if binary == "00":
                return "10"
            return binary
        cnt0 = 0
        for i in range(len(binary)):
            if binary[i] == "0":
                cnt0 += 1
        cnt1 = len(binary) - cnt0
        if cnt0 < 2:
            return binary
        i = 0
        res = ""
        while binary[i] == "1":
            i+=1
            res += "1"
            cnt1 -= 1
        for i in range(cnt0-1):
            res += "1"
        res += "0"
        for i in range(cnt1):
            res += "1"
        return res
        