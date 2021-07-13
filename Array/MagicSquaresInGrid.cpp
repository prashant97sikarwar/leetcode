//Problem Link:- https://leetcode.com/problems/magic-squares-in-grid/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        // calculating the rows prefix sums
        vector<vector<long long>> rowSums(n, vector<long long>(m, 0));
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=0; j<m; j++){
                sum+=grid[i][j];
                rowSums[i][j]=sum;
            }
        }
        
        // calculating colums prefix sums
        vector<vector<long long>> colSums(n, vector<long long>(m, 0));
        for(int i=0; i<m; i++){
            int sum=0;
            for(int j=0; j<n; j++){
                sum+=grid[j][i];
                colSums[j][i]=sum;
            }
        }
        
        
        // only squares of size atmost 'limit' can be allowed
        int limit=min(n,m);
        
        // trivially, squares of size 1 are all magic squares
        int ans=0;
        
        // calculating for all sizes from 2 to limit
        for(int i=3; i<=limit; i++){
            for(int r=0; r<n-i+1; r++){
                for(int c=0; c<m-i+1; c++){
                    long long prev;
                    long long sum;
                    bool rows=true;
                    bool cols=true;
                    bool diag=true;
                    vector<int> dp(10,0);
                    for(int x=r;x<r+i;x++){
                        for(int y=c;y<c+i;y++){
                            if (grid[x][y] >= 1 && grid[x][y] <= 9){
                                dp[grid[x][y]] += 1;
                            }
                        }
                    }
                    bool imp = true;
                    for(int p=1;p<=9;p++){
                        if (dp[p] != 1){
                            imp = false;
                            break;
                        }
                    }
                    if (imp == false){
                        continue;
                    }
               
                    
                    // checking if all rows in the square has same sum
                    for(int k=r; k<r+i; k++){
                        sum=rowSums[k][c+i-1];
                        sum-=(c>0)?rowSums[k][c-1]:0;
                        if(k==r){
                            prev=sum;
                        }else{
                            if(sum!=prev){
                                rows=false;
                                break;
                            }
                        }
                        prev=sum;
                    }
                    if(!rows){
                        continue;
                    }
                    
                    // checking if all columns in the square has same sum as rows
                    for(int k=c; k<c+i; k++){
                        sum=colSums[r+i-1][k];
                        sum-=(r>0)?colSums[r-1][k]:0;
                        if(sum!=prev){
                            cols=false;
                            break;
                        }
                        prev=sum;
                    }
                    if(!cols){
                        continue;
                    }
                    
                    // checking if the primary diagonal has same sum as rows and columns
                    sum=0;
                    for(int k=0; k<i; k++){
                        sum+=grid[r+k][c+k];
                    }
                    if(sum!=prev){
                        diag=false;
                        continue;
                    }
                    
                    // checking if the non primary diagonal has same sum as all above
                    sum=0;
                    for(int k=0; k<i; k++){
                        sum+=grid[r+k][c+i-k-1];
                    }
                    if(sum!=prev){
                        diag=false;
                        continue;
                    }
                    
                    // if all the rows, columns and diagonals have same sum, update the answer
                    if(rows && cols && diag && imp){
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};