//Problem Link:-https://leetcode.com/problems/number-complement/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        long long res = 0;
        int k = num;
        int cnt = 0;
        while (k > 0){
            cnt++;
            k >>= 1;
        }
        for(int i=0;i<cnt;i++){
            res |= (1 << i);
        }
        
        return res ^ num;
    }
};