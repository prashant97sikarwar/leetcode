#Problem Link:- https://leetcode.com/problems/minimum-number-of-people-to-teach/

"""n a social network consisting of m users and some friendships between users, two users can 
communicate with each other if they know a common language.You are given an integer n, an array 
languages, and an array friendships where:There are n languages numbered 1 through n,languages[i]
is the set of languages the i​​​​​​th​​​​ user knows, and friendships[i] = [u​​​​​​i​​​, v​​​​​​i] denotes a friendship 
between the users u​​​​​​​​​​​i​​​​​ and vi.You can choose one language and teach it to some users so that all 
friends can communicate with each other. Return the minimum number of users you need to teach.
Note that friendships are not transitive, meaning if x is a friend of y and y is a friend of z, 
this doesn't guarantee that x is a friend of z. """"

class Solution(object):
    def minimumTeachings(self, n, languages, friendships):
        s  =  set()
        for u,v in friendships:
            if self.helper(languages,u,v) == False:
                s.add(u)
                s.add(v)
        res = 1000
        for i in range(1,n+1):
            cnt = 0
            for p in s:
                if i not in languages[p-1]:
                    cnt += 1
            res = min(res,cnt)
        return res
            
    def helper(self,languages,u,v):
        for i in range(len(languages[u-1])):
            for j in range(len(languages[v-1])):
                if languages[u-1][i] == languages[v-1][j]:
                    return True
        return False
    