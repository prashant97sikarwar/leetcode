//Problem Link:- https://leetcode.com/problems/count-of-smaller-numbers-after-self/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    class Node{
        public:
        int lc;
        Node* left, *right;
        int data;
        Node(int val){
            lc = 0;
            data = val;
            left = NULL, right = NULL;
        }
    };
public:
    
    int helper(Node* node,int key){
        Node *r=NULL,*p;  
        int c = 0;
        while(node!=NULL){
            r=node;
            if( (node->data)>=key)
            {
              node->lc=(node->lc)+1;
                node=node->left;
            }
            else{
               c+= 1 + (node->lc);
                node=node->right;
            }
        }
        p=new Node(key);
        if(p->data<=r->data)
        r->left=p;
        else
            r->right=p;
        return c;
    }
    vector<int> countSmaller(vector<int>& nums) {
       const int len = nums.size();
        vector<int> result(len,0);
        int idx = 1;
        while (idx < len && nums[idx] >= nums[idx-1]){
            idx++;
        }
        if (idx == len){
            return result;
        }
        idx = len-2;
        while (idx >= 0 && nums[idx] >= nums[idx+1]){
            if (nums[idx] > nums[idx+1]){
                result[idx] = len-idx-1;
            }
            else if (nums[idx+1] == nums[idx]){
                result[idx] = result[idx+1];
            }
            idx--;
        }
        if (idx < 0){
            return result;
        }
        for(int i=0;i<len;i++){
            result[i] = 0;
        }
        Node* root = new Node(nums[len-1]);
        for(int i=len-2;i>=0;i--){
            result[i] = helper(root,nums[i]);
        }
        return result;
    }
};