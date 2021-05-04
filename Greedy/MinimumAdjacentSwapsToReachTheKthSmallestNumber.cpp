//Problem Link:- https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinSwaps(string n, int k) {
        string n1 = n;
        int res = 0;
        while(k--){
            next_permutation(n1.begin(),n1.end());
        }
        for (auto i = 0; i < n.size(); ++i) {
            if (n[i] != n1[i]) {
                for (auto j = i + 1; j < n.size(); ++j) {
                    if (n[i] == n1[j]) {
                        res += j - i;
                        n1 = n1.substr(0, i + 1) + n1.substr(i, j - i) + n1.substr(j + 1);
                        break;
                    }
                }
            }
        }
    return res;
    }
};