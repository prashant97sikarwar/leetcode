//Problem link:- https://leetcode.com/problems/delete-node-in-a-linked-list/

/* Write a function to delete a node in a singly-linked list. You will not be given access 
to the head of the list, instead you will be given access to the node to be deleted directly.
It is guaranteed that the node to be deleted is not a tail node in the list.*/

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
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next->next;
        ListNode* nxt = node->next;
        node->val = nxt->val;
        node->next = temp;
    }
};
