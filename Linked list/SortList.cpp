//Problem Link:- https://leetcode.com/problems/sort-list/

/* Given the head of a linked list, return the list after sorting it in ascending order.*/

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
    ListNode* merge(ListNode* first,ListNode* sec){
        ListNode* result = new ListNode(-1);
        ListNode* lst = result;
        while (first != NULL && sec != NULL){
            if (first->val <= sec->val){
                result->next = first;
                result = result->next;
                first = first->next;
            }
            else{
                result->next = sec;
                result = result->next;
                sec = sec->next;
            }
        }
        while (first != NULL){
            result->next = first;
            result = result->next;
            first = first->next;
        }
        while (sec != NULL){
            result->next = sec;
            result = result->next;
            sec = sec->next;
        }
        return lst->next;
    }
    
    ListNode* NodeMid(ListNode* head, ListNode* tail){
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != tail && fast != tail){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* MergeSort(ListNode* head, ListNode* tail){
        if (head == tail){
            ListNode* br = new ListNode(head->val);
            return br;
        }
        ListNode* mid = NodeMid(head,tail);
        ListNode* first = MergeSort(head,mid);
        ListNode* sec = MergeSort(mid->next,tail);
        return merge(first,sec);
    }
    
    ListNode* sortList(ListNode* head) {
        ListNode* tail = head;
        if (head == NULL){
            return head;
        }
        if (head->next == NULL){
            return head;
        }
        while (tail->next != NULL){
            tail = tail->next;
        }
        return MergeSort(head,tail);
    }
};