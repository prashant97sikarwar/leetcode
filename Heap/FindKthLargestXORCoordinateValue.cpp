//Problem Link:- https://leetcode.com/contest/weekly-contest-225/problems/find-kth-largest-xor-coordinate-value/

/* You are given a 2D matrix of size m x n, consisting of non-negative integers. You are also 
given an integer k.The value of coordinate (a, b) of the matrix is the XOR of all matrix[i][j]
where 0 <= i <= a < m and 0 <= j <= b < n (0-indexed).Find the kth largest value (1-indexed) 
of all the coordinates of matrix. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        for(int i=1;i<matrix.size();i++){
            matrix[i][0] ^= matrix[i-1][0];
        }
        for(int i=1;i<matrix[0].size();i++){
            matrix[0][i] ^= matrix[0][i-1];
        }
        for(int i=1;i < matrix.size();i++){
            for(int j=1;j < matrix[0].size();j++){
                matrix[i][j] ^= matrix[i-1][j] ^ matrix[i][j-1] ^ matrix[i-1][j-1]; 
            }
        }
        priority_queue <int, vector<int>, greater<int> > pq;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if (pq.size() < k){
                    pq.push(matrix[i][j]);
                }
                else if (pq.top() < matrix[i][j]){
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
            }
        }
        return pq.top();
        
    }
};