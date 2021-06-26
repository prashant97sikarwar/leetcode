//Problem Link:- https://practice.geeksforgeeks.org/problems/a512e4b2e812b6df2159b19cc7090ffc1ab056dd/1/#

#include<bits/stdc++.h>
using namespace std;

class Solution{   
    private:
    class Node{
        public:
        Node* left;
        Node* right;
        int value;
        
        Node(){
            left = NULL;
            right = NULL;
            value = 0;
        }
    };
public:
    int search(Node* root, int prexor){
        Node* cur = root;
        for(int i=31;i>=0;i--){
            int bit = (1 << i) & prexor;
            if (bit == 0){
                if (cur->right){
                    cur = cur->right;
                }
                else{
                    cur = cur->left;
                }
            }
            else{
                if (cur->left){
                    cur = cur->left;
                }
                else{
                    cur = cur->right;
                }
            }
        }
        return prexor ^ (cur->value);
    }
    
    void insert(Node* root,int prexor){
        Node* cur = root;
        for(int i=31;i>=0;i--){
            int bit = (1 << i) & prexor;
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
        cur->value = prexor;
    }

    int maxSubarrayXOR(int n, int nums[]){    
        Node* root = new Node();
        int prexor = 0;
        insert(root,0);
        int res = INT_MIN;
        for(int i=0;i<n;i++){
            prexor ^= nums[i];
            insert(root,prexor);
            res = max(res,search(root,prexor));
        }
        return res;
    }
};