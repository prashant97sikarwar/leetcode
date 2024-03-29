# Problem Link :- https://leetcode.com/problems/task-scheduler/
"""Given a characters array tasks, representing the tasks a CPU needs to do, where each 
letter represents a different task. Tasks could be done in any order. Each task is done 
in one unit of time. For each unit of time, the CPU could complete either one task or just 
be idle.However, there is a non-negative integer n that represents the cooldown period between 
two same tasks Return the least number of units of times that the CPU will take to finish all 
the given tasks."""

class Solution(object):
    def leastInterval(self, tasks, n):
        arr = [0 for i in range(26)]
        for x in tasks:
            arr[ord(x)-ord('A')] += 1
        arr.sort()
        max_values = arr[25] - 1
        slot = max_values * n
        for i in range(24,-1,-1):
            slot -= min(arr[i],max_values)
        return slot + len(tasks) if slot > 0 else len(tasks)