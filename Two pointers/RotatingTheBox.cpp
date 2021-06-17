//Problem Link:- https://leetcode.com/problems/rotating-the-box/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box){
        int n = box.size();
        int m = box[0].size();
        for(int i=0;i<n;i++){
            int cnt = 0;
            int prev = -1;
            for(int j=0;j<m;j++){
                if (j == m-1 && box[i][j] != '*'){
                    if (box[i][j] == '#'){
                        cnt++;
                    }
                    if (cnt > 0 && cnt <= j-prev){
                        int idx = j;
                        while (cnt--){
                            box[i][idx] = '#';
                            idx--;
                        }
                    }
                }
                else if (box[i][j] == '*'){
                    if (cnt > 0 && cnt <= j-prev -1){
                        int idx = j-1;
                        while (cnt--){
                            box[i][idx] = '#';
                            idx--;
                        }
                    }
                    prev = j;
                    cnt = 0;
                }
                else if (box[i][j] == '#'){
                    cnt++;
                    box[i][j] = '.';
                }
            }
        }
        vector<vector<char>> result(m,vector<char> (n,'.'));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result[j][i] = box[i][j];
            }
        }
        for(int i=0;i<m;i++){
            int l = 0;
            int r = n-1;
            while (l <= r){
                swap(result[i][l],result[i][r]);
                l++;
                r--;
            }
        }
        return result;
    }
};