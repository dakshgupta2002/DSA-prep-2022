#include <bits/stdc++.h>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=NULL, *tail=NULL;
        ListNode *temp1=list1, *temp2=list2;
        ListNode* temp;

        while (temp1 || temp2){
            if ((temp1 && temp2 && temp1->val < temp2->val) || temp2==NULL){
                temp=temp1;
                temp1=temp1->next;
            }else{
                temp=temp2;
                temp2=temp2->next;
            }

            //insert the node to the new list
            if (head==NULL){
                head=temp; tail=temp;
            }else{
                tail->next=temp;
                tail = tail->next;
            }
        }
        return head;
    }
};