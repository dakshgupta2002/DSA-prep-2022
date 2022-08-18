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
//Reverse half of other list and then two pointer
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
    }
};


class Solution2 {
public:
    bool isPal(string &s){
        int i=0, j=s.length()-1;
        while (i<j){
            if (s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        string s="";
        while (head){
            s+=(head->val + '0');
            head=head->next;
        }      
        return isPal(s);
    }
};