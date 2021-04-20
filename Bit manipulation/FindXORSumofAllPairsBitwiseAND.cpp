//Problem Link:- https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/

/*You are given two 0-indexed arrays arr1 and arr2 that consist only of non-negative 
integers.Consider the list containing the result of arr1[i] AND arr2[j] (bitwise AND) 
for every (i, j) pair where 0 <= i < arr1.length and 0 <= j < arr2.length.Return the 
XOR sum of the aforementioned list.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int f = 0;
        for(int i=0;i<arr1.size();i++){
            f ^= arr1[i];
        }
        int s = 0;
        for(int i=0;i<arr2.size();i++){
            s ^= arr2[i];
        }
        return s&f;
    }
};