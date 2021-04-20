//Problem Link:- https://leetcode.com/problems/remove-linked-list-elements/

/* Given the head of a linked list and an integer val, remove all the nodes of the linked 
list that has Node.val == val, and return the new head.*/

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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val){
            head = head->next;
        }
        if (head == NULL){
            return head;
        }
        if (head->next == NULL){
            return head;
        }
        ListNode* curr = head;
        while (curr != NULL && curr->next != NULL){
            ListNode* temp = curr->next;
            while (temp != NULL && temp->val == val){
                temp = temp->next;
            }
            curr->next = temp;
            curr = curr->next;
        }
        return head;
    }
};