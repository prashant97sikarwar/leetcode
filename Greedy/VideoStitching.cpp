//Problem Link:- https://leetcode.com/problems/video-stitching/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        const int n = clips.size();
        sort(clips.begin(),clips.end());
        int cnt = 0,end = 0;
        for(int i=0;i<n;i++){
            if (clips[i][1] < end){
                continue;
            }
            else if (clips[i][0] > end){
                return -1;
            }
            int j = i, newEnd = end;
            cnt++;
            while (j < n && clips[j][0] <= end){
                newEnd = max(newEnd,clips[j][1]);
                j++;
            }
            end =  newEnd;
            i = j-1;
            if (end >= time){
                return cnt;
            }
        }
        return (end == time ? cnt : -1);
    }
};