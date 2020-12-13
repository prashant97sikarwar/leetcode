#Problem Link :- https://leetcode.com/problems/open-the-lock/

"""You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: 
'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap 
around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of 
turning one wheel one slot.The lock initially starts at '0000', a string representing the 
state of the 4 wheels.You are given a list of deadends dead ends, meaning if the lock 
displays any of these codes, the wheels of the lock will stop turning and you will be 
unable to open it.Given a target representing the value of the wheels that will unlock 
the lock, return the minimum total number of turns required to open the lock, or -1 if 
it is impossible."""

class Solution(object):
    def openLock(self, deadends, target):
        deadends = set(deadends)
        def helper(s):
            lst = []
            for i,c in enumerate(s):
                for d in [-1,1]:
                    lst.append(s[:i] + str((int(c)+d)%10) + s[i+1:])
            return lst
        if '0000' in deadends:
            return -1
        if "0000" == target:
            return 0
        q = deque(["0000"])
        dist = {}
        dist["0000"] = 0
        while q:
            node = q.popleft()
            d = 1 + dist[node]
            lst =  helper(node)
            for x in lst:
                if x not in deadends and x not in dist:
                    if x == target:
                        return d
                    dist[x] = d
                    q.append(x)
        return -1