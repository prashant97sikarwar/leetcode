//Problem Link:- https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

/*Given an integer array arr. You have to sort the integers in the array in ascending order by 
the number of 1's in their binary representation and in case of two or more integers have the 
same number of 1's you have to sort them in ascending order.Return the sorted array.*/

#include<bits/stdc++.h>
using namespace std;

int helper(int n){
    int res = 0;
    while(n > 0){
        res++;
        n = n & (n-1);
    }
    return res;
}

bool cmp(int a, int b){
    int c1 = helper(a);
    int c2 = helper(b);
    if (c1 < c2){
        return true;
    }
    else if (c2 < c1){
        return false;
    }
    else{
        return a < b;
    }
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};