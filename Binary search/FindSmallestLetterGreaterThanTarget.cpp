//Problem Link:- https://leetcode.com/problems/find-smallest-letter-greater-than-target/

/*Given a list of sorted characters letters containing only lowercase letters, and given a target 
letter target, find the smallest element in the list that is larger than the given target.Letters 
also wrap around. */


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char helper(int l, int r,vector<char>& letters,char target){
        char ans = letters[0];
        while (l <= r){
            int mid = l + (r-l)/2;
            if (letters[mid] > target){
                ans = letters[mid];
                cout << ans <<endl;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
    
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        return helper(0,n-1,letters,target);
    }
};
