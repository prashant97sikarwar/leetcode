//Problem Link:- https://leetcode.com/problems/slowest-key/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char slowestKey(vector<int>& times, string chars) {
        const int n = chars.size();
        char result = chars[0];
        int duration = times[0];
        for(int i=1;i<n;i++){
            int newd = times[i] - times[i-1];
            if (newd > duration){
                duration = newd;
                result = chars[i];
            }
            else if (newd == duration){
                if (chars[i] > result){
                    result = chars[i];
                }
            }
            else{
                continue;
            }
        }
        return result;   
    }
};