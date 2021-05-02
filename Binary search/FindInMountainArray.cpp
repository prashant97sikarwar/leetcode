//Problem Link:- https://leetcode.com/problems/find-in-mountain-array/

#include<bits/stdc++.h>
using namespace std;

class MountainArray {
public:
    int get(int index);
    int length();
};

class Solution {
public:
    int bleft(MountainArray &mountainArr,int l,int r,int target){
        while (l <= r){
            int mid = l + (r-l)/2;
            int val = mountainArr.get(mid);
            if (val == target){
                return mid;
            }
            else if (val > target){
                r = mid-1;
            }
            else if (val < target){
                l = mid+1;
            }
        }
        return -1;
    }
    
    int bright(MountainArray &mountainArr,int l,int r,int target){
        while ( l <= r){
            int mid = l + (r-l)/2;
            int val = mountainArr.get(mid);
            if (val == target){
                return mid;
            }
            else if(val < target){
                r = mid-1;   
            }
            else if (val > target){
                l = mid+1;
            }
        }
        return -1;
    }
    
    int larget(MountainArray &mountainArr){
        int l = 0;
        int r = mountainArr.length()-1;
        while (l < r){
            int mid = l + (r-l)/2;
            if (mountainArr.get(mid) < mountainArr.get(mid+1)){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return l;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = larget(mountainArr);
        if (target > mountainArr.get(peak)){
            return -1;
        }
        int left = bleft(mountainArr,0,peak,target);
        if (left != -1){
            return left;
        }
        int right = bright(mountainArr,peak+1,mountainArr.length()-1,target);
        return right;
    }
};