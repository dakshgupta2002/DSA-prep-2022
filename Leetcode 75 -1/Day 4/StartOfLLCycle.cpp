#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head, *fast=head;
        //if cycle exists they will meet inside the loop at once
        while (slow && fast){
            slow = slow->next;
            fast=fast->next;
            if (fast) fast = fast->next;

            if (slow==fast) break;
        }
        //if there isnt a loop, then fast will be NULL ofcourse
        if (fast==NULL || slow==NULL) return NULL;
        // finding the tail pointer to the loop 
        fast = head;
        while (fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};