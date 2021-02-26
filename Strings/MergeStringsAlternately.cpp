//Problem Link:- https://leetcode.com/contest/weekly-contest-229/problems/merge-strings-alternately/

/* You are given two strings word1 and word2. Merge the strings by adding letters in alternating 
order, starting with word1. If a string is longer than the other, append the additional letters 
onto the end of the merged string.Return the merged string. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int i = 0, j = 0, cnt = 0;
        string s;
        while(i < n && j < m){
            if (cnt % 2 == 0){
                s.push_back(word1[i]);   
                i++;
            }
            else{
                s.push_back(word2[j]);
                j++;
            }
            cnt++;
        }
        while(i < n){
            s.push_back(word1[i]);
            i++;
        }
        while(j < m){
            s.push_back(word2[j]);
            j++;
        }
        return s;
    }
};