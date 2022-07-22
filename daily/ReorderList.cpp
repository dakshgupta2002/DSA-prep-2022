#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return NULL;

        ListNode *temp = head, *insert = NULL;
        if (temp->val < x){
            while (temp && temp->next && temp->next->val < x) {
                temp = temp->next;
            }
            insert = temp;
        }


        while (temp && temp->next){
            if (temp->next->val < x ){
                //re-position this node ahead of insert 
                ListNode* after = temp->next->next;
                if (insert == NULL){
                    temp->next->next = head;
                    head = temp->next;
                    temp->next = after;
                    insert = head;
                }else{
                    temp->next->next = insert->next;
                    insert->next = temp->next;
                    temp->next = after;
                    insert = insert->next;
                }
            }else temp = temp->next;
        }
        return head;
    }
};