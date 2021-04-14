//problem Link:- https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* tail = head;
        if (head == NULL){
            return head;
        }
        if (head->next == NULL){
            return head;
        }
        tail = head->next;
        while (curr != NULL && curr->next != NULL){
            while (tail != NULL && curr->val == tail->val){
                tail = tail->next;
            }
            curr->next = tail;
            curr = curr->next;
            if (tail != NULL){
                tail = tail->next;   
            }
        }
        return head;
    }
};