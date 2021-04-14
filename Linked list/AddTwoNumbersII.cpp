//Problem Link:- https://leetcode.com/problems/add-two-numbers-ii/

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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt;
        while (curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first = reverse(l1);
        ListNode* sec = reverse(l2);
        ListNode* ans = new ListNode(-1);
        ListNode* res = ans;
        int carry = 0;
        int sm = 0;
        while (first != NULL && sec != NULL){
            sm = first->val + sec->val + carry;
            carry = sm / 10;
            int dg = sm % 10;
            ans->next = new ListNode(dg);
            ans = ans->next;
            first = first->next;
            sec = sec->next;
        }
        while (first != NULL){
            sm = carry + first->val;
            carry = sm / 10;
            int dg = sm % 10;
            ans->next = new ListNode(dg);
            ans = ans->next;
            first = first->next;
        }
        while (sec != NULL){
            sm = carry + sec->val;
            carry = sm / 10;
            int dg = sm  % 10;
            ans->next = new ListNode(dg);
            ans = ans->next;
            sec = sec->next;
        }
        if (carry > 0){
            ans->next = new ListNode(carry);
        }
        first = reverse(res->next);
        return first;
    }
};