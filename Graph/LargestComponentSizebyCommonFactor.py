#Problem Link: https://leetcode.com/problems/largest-component-size-by-common-factor/

"""Given a non-empty array of unique positive integers A, consider the following graph:
There are A.length nodes, labelled A[0] to A[A.length - 1];There is an edge between A[i]
and A[j] if and only if A[i] and A[j] share a common factor greater than 1.Return the 
size of the largest connected component in the graph."""

class Solution:
    def largestComponentSize(self, A: List[int]) -> int:
        parents = {val:val for val in A}
        sizes = {val:1 for val in A}
        factorprez = {} # we only need to store one representative for each prime factor
        maxsize = 0
        
        def union(one, two):
            '''join two nodes and return the size of the resulting group'''
            r1 = findroot(one)
            r2 = findroot(two)
            
            if r1 == r2: return sizes[r1]
            
            big, small = (r1, r2) if sizes[r1] > sizes[r2] else (r2, r1)
            parents[small] = big
            sizes[big] += sizes[small]
            return sizes[big]
            
        def findroot(node):
            if parents[node] != node:
                node = findroot(parents[node])
            return parents[node]
        
        def primes_before(val):
            '''return all the prime numbers before and including this value'''
            candidates = [True] * (val + 1)
            primes = []
            for i in range(2, len(candidates)):
                if not candidates[i]: continue
                primes.append(i)
                for j in range(i, val+1, i):
                    candidates[j] = False
            return primes
        
        primes = primes_before(100000)
        primeset = set(primes)
        
        for val in A:
			# break down each number by primes while it breaks
            sval = val
            prime_idx = 0
            while sval not in primeset and primes[prime_idx] <= sval:
                if sval % primes[prime_idx] == 0:
                    if primes[prime_idx] in factorprez:
                        maxsize = max(maxsize, union(val, factorprez[primes[prime_idx]]))
                    else:
                        factorprez[primes[prime_idx]] = val
                    
                    while sval % primes[prime_idx] == 0:
                        sval //= primes[prime_idx]
                
                prime_idx += 1
            
            if sval in primeset:
                if sval in factorprez:
                    maxsize = max(maxsize, union(val, factorprez[sval]))
                else:
                    factorprez[sval] = val


        return maxsize
