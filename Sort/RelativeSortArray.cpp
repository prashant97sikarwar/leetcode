//Problem link:- https://leetcode.com/problems/relative-sort-array/submissions/

/*Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are 
also in arr1.Sort the elements of arr1 such that the relative ordering of items in arr1 are the 
same as in arr2.  Elements that don't appear in arr2 should be placed at the end of arr1 in 
ascending order.*/

#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> ump;
bool cmp(int a, int b){
    if (ump.count(a) && ump.count(b)){
        return ump[a] < ump[b];
    }
    else if (ump.count(a) && !ump.count(b)){
        return true;
    }
    else if (!ump.count(a) && ump.count(b)){
        return false;
    }
    else{
        return a < b;
    }
} 
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        for(int i=0;i<arr2.size();i++){
            ump[arr2[i]] = i;
        }
        sort(arr1.begin(),arr1.end(),cmp);
        ump.clear();
        return arr1;
    }
};