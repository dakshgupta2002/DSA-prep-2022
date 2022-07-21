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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *s=NULL, *l, *r, *e=NULL;
        ListNode* temp=head;

        int i=1;
        while (temp){
            if (i==left-1) s=temp;
            if (i==left) l=temp;
            if (i==right) r=temp;
            if (i==right+1) e=temp;
            i++;
            temp=temp->next;
        } 
        
        ListNode* prev=l, *curr=l->next, *forw=NULL;
        while (curr && curr!=e){
            forw = curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }

        l->next = e;
        if (s) s->next = r;
        else head=r;

        return head;
    }
};