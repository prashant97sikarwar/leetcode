//Problem Link:- https://leetcode.com/problems/palindrome-linked-list/

#include<bits/stdc++.h>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    
    ListNode* helper(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt;
        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* node = NULL;
        node = new ListNode(head->val);
        ListNode* temp = head;
        head = head->next;
        ListNode* start = node;
        while (head != NULL){
            node->next = new ListNode(head->val);
            head = head->next;
            node = node->next;
        }
        head = helper(temp);
        while (head != NULL && start != NULL){
            if (head->val != start->val){
                return false;
            }
            head = head->next;
            start = start->next;
        }
        return true;
    }
};