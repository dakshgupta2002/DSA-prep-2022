#include <bits/stdc++.h>
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
    // delete and insert odd nodes ahead of 1
    ListNode* oddEvenList(ListNode* head) {
        if (head==NULL) return NULL;
        ListNode *temp = head, *oddTail=head;
        int i=1;

        while(temp && temp->next){
            if (i%2==0){ 
                //pointer to the next odd node
                ListNode *newOdd = temp->next;
                temp->next = temp->next->next;
                //inserting ahead of odds
                newOdd->next = oddTail->next;
                oddTail->next =newOdd;
                //updating tail of odds
                i++;
                oddTail = oddTail->next;
            }
            i++;
            temp=temp->next;
        }
        return head;
    }
};

class Solution2{
    ListNode* oddEvenList(ListNode* head){
        if (head==NULL || head->next==NULL) return head;

        ListNode *oddHead = head, *oddTail = head, *evenHead=head->next, *evenTail = head->next;

        int i = 3;
        ListNode *itr = head->next->next;

        while (itr){
            if (i%2==1){
                oddTail->next = itr;
                oddTail = oddTail->next;
            }else{
                evenTail->next = itr;
                evenTail = evenTail->next;
            }
            i++;
            itr=itr->next;
        }
        oddTail->next = evenHead;
        evenTail->next = nullptr;

        return oddHead;
    }
};