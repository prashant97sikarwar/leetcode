//Problem Link:- https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    class Node{
        public:
        Node* left;
        Node* right;
    };
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[1] < b[1];
    }
    
    void insert(Node* root,int n){
        Node* cur = root;
        for(int i=31;i>=0;i--){
            int bit = (1 << i) & n;
            if (bit == 0){
                if (!cur->left){
                    cur->left = new Node();
                }
                cur = cur->left;
            }
            else{
                if (!cur->right){
                    cur->right = new Node();
                }
                cur = cur->right;
            }
        }
    }
    
    int search(Node* root,int n){
        Node* cur = root;
        if (cur == NULL){
            return -1;
        }
        int val = 0;
        for(int i=31;i>=0;i--){
            int bit = (1 << i) & n;
            if (cur == NULL){
                return -1;
            }
            if (bit == 0){
                if (cur->right){
                    val += pow(2,i);
                    cur = cur->right;
                }
                else{
                    cur = cur->left;
                }
            }
            else{
                if (cur->left){
                    val += pow(2,i);
                    cur = cur->left;
                }
                else{
                    cur = cur->right;
                }
            }
        }
        return val;
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Node* root = new Node();
        sort(nums.begin(),nums.end());
        int i = 0;
        for(auto &q : queries){
            q.push_back(i++);
        }
        sort(queries.begin(),queries.end(),cmp);
        vector<int> result(queries.size());
        i = 0;
        for(auto q : queries){
            while (i < nums.size() && nums[i] <= q[1]){
                insert(root,nums[i++]);
            }
            int output;
            if (!root){
                output = -1;
            }
            else{
                output = search(root,q[0]);   
            }
            result[q[2]] = output;
        }
        return result;
    }
};