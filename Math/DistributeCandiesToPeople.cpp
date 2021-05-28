//Problem Link:- https://leetcode.com/problems/distribute-candies-to-people/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int people) {
        vector<int> result(people,0);
        int sm = 1;
        bool flag = false;
        while (candies > 0){
            for(int i=0;i<people;i++){
                result[i] += min(sm,candies);
                candies -= sm;
                if (candies <= 0){
                    flag = true;
                    break;
                }
                sm++;
            }
            if (flag){
                break;
            }
        }
        return result;
    }
};