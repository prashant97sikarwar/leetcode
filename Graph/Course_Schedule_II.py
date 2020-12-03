#Problem Link:- https://leetcode.com/problems/course-schedule-ii/

"""There are a total of n courses you have to take labelled from 0 to n - 1.Some courses 
may have prerequisites, for example, if prerequisites[i] = [ai, bi] this means you must 
take the course bi before the course ai.Given the total number of courses numCourses and 
a list of the prerequisite pairs, return the ordering of courses you should take to 
finish all courses."""

class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        from collections import defaultdict
        graph = defaultdict(list)
        res = []
        ind = [0]*numCourses
        for first,sec in prerequisites:
            graph[sec].append(first)
            ind[first] += 1
        q = []
        for i in range(numCourses):
            if ind[i] == 0:
                q.append(i)
        while len(q) > 0:
            node = q.pop(0)
            res.append(node)
            for x in graph[node]:
                ind[x] -= 1
                if ind[x] == 0:
                    q.append(x)
        return res if len(res) == numCourses else []