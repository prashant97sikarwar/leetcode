//Problem Link:- https://leetcode.com/problems/maximize-the-confusion-of-an-exam/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        const int n = s.length();
        int result = 0, left = 0, maxCnt = 0;
        int t = 0, f = 0;
        for(int i=0;i<n;i++){
            if (s[i] == 'T'){
                t++;
                if (t > maxCnt){
                    maxCnt = t;
                }
            }
            else if (s[i] == 'F'){
                f++;
                if (f > maxCnt){
                    maxCnt = f;
                }
            }
            while (left < n && i-left + 1 > maxCnt + k){
                if (s[left] == 'T'){
                    t--;
                }
                else if (s[left] == 'F'){
                    f--;
                }
                maxCnt = max(t, f);
                left++;
            }
            result = max(result, i - left + 1);
        }
        return result;
        
    }
};