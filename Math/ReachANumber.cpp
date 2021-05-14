//Problem Link:- https://leetcode.com/problems/reach-a-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        int n = abs(target);
        int k = 0;
        while (n > 0){
            k++;
            n -= k;
        }
        return (n % 2 == 0) ? k : k+1+k%2;
    }
};