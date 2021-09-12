//Problem Link:- https://leetcode.com/problems/search-a-2d-matrix/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        const int n = matrix.size();
        const int m = matrix[0].size();
        
        int right = n*m - 1;
        
        while (left <= right){
            int mid = left + (right - left)/2;
            int x = mid / m;
            int y = mid % m;
            if (matrix[x][y] == target){
                return true;
            }
            else if (matrix[x][y] > target){
                right = mid - 1;
            }
            else{
                left = mid +1;
            }
        }
        return false;
    }
};