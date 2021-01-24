//Problem Link:- https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/

/* You are given two strings a and b that consist of lowercase letters. In one operation, 
you can change any character in a or b to any lowercase letter.Your goal is to satisfy one 
of the following three conditions:Every letter in a is strictly less than every letter in b 
in the alphabet.Every letter in b is strictly less than every letter in a in the alphabet.
Both a and b consist of only one distinct letter.Return the minimum number of operations 
needed to achieve your goal. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arr1[26];
    int arr2[26];
    int minCharacters(string a, string b) {
        memset(arr1,0,sizeof(arr1));
        memset(arr2,0,sizeof(arr2));
        for(int i=0;i<a.length();i++){
            arr1[int(a[i])-'a']++;
        }
        for(int i=0;i<b.length();i++){
            arr2[int(b[i])-'a']++;
        }
        int ans;
        int mx = 0;
        for(int i=0;i<26;i++)
            mx = max(arr1[i] + arr2[i],mx);
        ans = a.length() + b.length() - mx;
        for(int i=1;i<26;i++){
            arr1[i] += arr1[i-1];
            arr2[i] += arr2[i-1];
        }
        for(int i=1;i<26;i++){
            ans = min(ans,min(arr1[i-1] + arr2[25] - arr2[i-1],arr2[i-1] + arr1[25] - arr1[i-1]));
        }
        return ans;
    }
};