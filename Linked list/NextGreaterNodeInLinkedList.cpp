//Problem Link:- https://leetcode.com/problems/next-greater-node-in-linked-list/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result;
        ListNode* curr = head;
        while (curr != NULL){
            ListNode* temp = curr;
            bool flag = false;
            while (temp != NULL){
                if (temp->val > curr->val){
                    result.push_back(temp->val);
                    flag = true;
                    break;
                }
                temp = temp->next;
            }
            if (temp == NULL && flag == false){
                result.push_back(0);
            }
            curr = curr->next;
        }
        return result;
    }
};