//Problem Link:- https://leetcode.com/problems/sentence-similarity-iii/

/* Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are 
similar. Otherwise, return false.wo sentences sentence1 and sentence2 are similar if it is 
possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such 
that the two sentences become equal. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        if (n == 1 && m == 1)
            return str1 == str2;
        vector<string> first;
        vector<string> sec;
        string ch = "";
        for(int i=0;i<n;i++){
            if (str1[i] == ' '){
                first.push_back(ch);
                ch = "";
            }
            else{
                ch += str1[i];
            }
        }
        first.push_back(ch);
        ch = "";
        for(int i=0;i<m;i++){
            if (str2[i] == ' '){
                sec.push_back(ch);
                ch = "";
            }
            else{
                ch += str2[i];
            }
        }
        sec.push_back(ch);
        if (sec.size() > first.size()){
            first.swap(sec);
        }
        int st = 0;
        while (st < first.size() && st < sec.size()){
            if (first[st] != sec[st])
                break;
            st++;
        }
        int end = first.size()-1;
        int e = sec.size()-1;
        while (end >= 0 && e >= 0){
            if (first[end] != sec[e]){
                break;
            }
            end--;
            e--;
        }
        if (st <= e){
            return false;
        }
        return true;
    }
};