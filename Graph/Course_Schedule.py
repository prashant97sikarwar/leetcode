#Problem Link :- https://leetcode.com/problems/course-schedule/

"""There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
Some courses may have prerequisites, for example to take course 0 you have to first take 
course 1, which is expressed as a pair: [0,1]Given the total number of courses and a list of 
prerequisite pairs, is it possible for you to finish all courses?"""

class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        if len(prerequisites) == 0:
            return True
        from collections import defaultdict
        graph = defaultdict(list)
        n = len(prerequisites)
        for i in range(n):
            graph[prerequisites[i][0]].append(prerequisites[i][1])
            
        def helper(cur,graph,visited,recur):
            visited[cur] = True
            recur[cur] = True
            for x in graph[cur]:
                if visited[x] == False:
                    if helper(x,graph,visited,recur) == True:
                        return True
                elif recur[x] == True:
                    return True
            recur[cur] = False
            return False
        
        def isCyclic(numCourses,graph):
            visited = [False for i in range(numCourses)]
            recur = [False for i in range(numCourses)]
            for i in range(numCourses):
                if visited[i] == False:
                    if helper(i,graph,visited,recur) == True:
                        return True
            return False
        
        if isCyclic(numCourses,graph):
            return False
        return True