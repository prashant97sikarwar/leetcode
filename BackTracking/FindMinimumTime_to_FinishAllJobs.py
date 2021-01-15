#Problem Link:- https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/

"""You are given an integer array jobs, where jobs[i] is the amount of time it takes to 
complete the ith job.There are k workers that you can assign jobs to. Each job should be 
assigned to exactly one worker. The working time of a worker is the sum of the time it 
takes to complete all jobs assigned to them. Your goal is to devise an optimal assignment 
such that the maximum working time of any worker is minimized.Return the minimum possible 
maximum working time of any assignment."""

class Solution(object):
    def minimumTimeRequired(self, jobs, k):
        jobs.sort(reverse = True)
        
        return self.dfs(0,jobs,[0]*k)
    
    def dfs(self,pos,jobs,workers):
        if pos >= len(jobs):
            return max(workers)
        
        mn = float("inf")
        visited = set()
        
        for sm in range(len(workers)):
            if workers[sm] in visited:
                continue
            visited.add(workers[sm])
            workers[sm] += jobs[pos]
            
            if max(workers) < mn:
                res = self.dfs(pos+1,jobs,workers)
                mn = min(mn,res)
            workers[sm] -= jobs[pos]
        return mn
        