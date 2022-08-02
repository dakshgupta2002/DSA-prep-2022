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
        if (left==right) return head;

        ListNode *s=NULL, *l, *r, *e=NULL;
        ListNode* temp=head;

        int i=1;
        while (temp){
            if (i==left-1) s=temp;

            if (i==left) {
                l=temp; 
                i++; temp=temp->next;
                ListNode* prev=l, *forw=NULL;
                while (temp && i<=right){
                    if (i==right) {
                        r=temp;
                        e=temp->next;
                    }

                    forw = temp->next;
                    temp->next=prev;
                    prev=temp;
                    temp=forw;

                    i++;
                }
                break;
            }
            i++;
            temp=temp->next;
        } 

        l->next = e;
        if (s) s->next = r;
        else head=r;

        return head;
    }
};