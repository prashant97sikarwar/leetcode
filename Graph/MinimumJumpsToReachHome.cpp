//Problem Link:- https://leetcode.com/problems/minimum-jumps-to-reach-home/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_map<int,int> mp;
        for(int i=0;i<forbidden.size();i++){
            mp[forbidden[i]] = 1;
        }
        if (mp[x] == 1){
            return -1;
        }
        if (x == 0){
            return 0;
        }
        queue<pair<int,char>> pq;
        pq.push({0,'f'});
        int level = 0;
        while(!pq.empty()){
            int sz = pq.size();
            bool flag = false;
            while (sz--){
                auto node = pq.front();
                pq.pop();
                int cor = node.first;
                char state = node.second;
                if (cor+a == x && mp[cor+a] != 1){
                    return level+1;
                }
                if (cor-b == x && mp[cor-b] != 1 && state == 'f'){
                    return level+1;
                }
                if (state == 'f' && mp[cor-b] != 1 && cor-b > 0){
                    pq.push({cor-b,'b'});
                    mp[cor-b] =1;
                }
                if (mp[cor+a] != 1 && cor+a > 0 && cor + a <= 2000+a+b){
                    pq.push({cor+a,'f'});
                    mp[cor+a] =1;
                }
            }
            level++;
        }
        return -1;
    }
};