#Problem Link :- https://leetcode.com/problems/boats-to-save-people/

"""The i-th person has weight people[i], and each boat can carry a maximum weight of limit.
Each boat carries at most 2 people at the same time, provided the sum of the weight of those 
people is at most limit.Return the minimum number of boats to carry every given person"""

class Solution(object):
    def numRescueBoats(self, people, limit):
        people.sort()
        low = 0
        high = len(people) - 1
        count = 0
        while low <= high:
            if people[low] + people[high] <= limit:
                count += 1
                low += 1
                high -= 1
            else:
                high -= 1
                count += 1
        return count