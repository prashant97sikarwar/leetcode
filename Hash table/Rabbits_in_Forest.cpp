//Problem Link:- https://leetcode.com/problems/rabbits-in-forest/

/* In a forest, each rabbit has some color. Some subset of rabbits (possibly all of them) tell 
you how many other rabbits have the same color as them. Those answers are placed in an array.
Return the minimum number of rabbits that could be in the forest. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int,int> ump;
        for(int i=0;i<n;i++){
            ump[answers[i]+1]++;
        }
        int res = 0;
        for(auto item : ump){
            int g = item.second / item.first;
            if (item.second % item.first > 0)
                g++;
            res += (g * item.first);
        }
        return res;
    }
};