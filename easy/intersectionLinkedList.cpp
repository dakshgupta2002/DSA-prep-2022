#include<bits/stdc++.h>
using namespace std;

// definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //if A and B share a node then the next nodes are also same 
        //so the difference in length is in the start 

        int a=0, b=0; 
        ListNode* A=headA, *B=headB;
        while (headA){
            a++; headA = headA->next;
        }
        while (headB){
            b++; headB = headB->next;
        }

        //move the larger head to the same distance 
        int diff = abs(a-b);
        if (a>b){
            while (diff--){
                A = A->next;
            }
        }
        else{
            while (diff--){
                B = B->next;
            }
        }

        //finally move the left distance i.e. same for both
        while (A != B){
            if (!A || !B){
                return NULL;
            }

            A = A->next;
            B = B->next;
        }
        return A;
    }
};