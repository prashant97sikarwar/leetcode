//Problem Link:- https://leetcode.com/problems/merge-in-between-linked-lists/

/* You are given two linked lists: list1 and list2 of sizes n and m respectively.Remove list1's 
nodes from the ath node to the bth node, and put list2 in their place.Build the result list and 
return its head.*/

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
    ListNode* mergeInBetween(ListNode* head, int a, int b, ListNode* list2) {
        ListNode* first = head;
        ListNode* sec = head;
        int cnt1 = 1;
        int cnt2 = 0;
        while (cnt1 != a){
            cnt1++;
            first = first->next;
        }
        while (cnt2 != b){
            cnt2++;
            sec = sec->next;
        }
        ListNode* temp = sec->next;
        first->next = list2;
        while (list2->next != NULL){
            list2 = list2->next;
        }
        list2->next = temp;
        return head;
    }
};