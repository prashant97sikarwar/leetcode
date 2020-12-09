#Problem Link:- https://leetcode.com/problems/course-schedule-iv/

"""There are a total of n courses you have to take, labeled from 0 to n-1.Some courses 
may have direct prerequisites, for example, to take course 0 you have first to take 
course 1, which is expressed as a pair: [1,0]Given the total number of courses n, a list 
of direct prerequisite pairs and a list of queries pairs.You should answer for each 
queries[i] whether the course queries[i][0] is a prerequisite of the course queries[i][1]
or not.Return a list of boolean, the answers to the given queries.Please note that if 
course a is a prerequisite of course b and course b is a prerequisite of course c, then, 
course a is a prerequisite of course c."""

class Solution(object):
    def checkIfPrerequisite(self, n, prerequisites, queries):
        if len(prerequisites) == 0:
            return [False for i in range(len(queries))]
        from collections import defaultdict
        graph = defaultdict(list)
        for u,v in prerequisites:
            graph[u].append(v)
        
        @lru_cache()
        def dfs(x,y):
            if x == y:
                return True
            for adj in graph[x]:
                if dfs(adj,y) == True:
                    return True
            return False
        
        ans  = []
        for u,v in queries:
            if v in graph[u]:
                ans.append(True)
            else:
                ans.append(dfs(u,v))
        return ans
                