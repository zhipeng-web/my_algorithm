//
// Created by china on 2024/2/2.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode *l3 = new ListNode();
       ListNode *cur = l3;
       int carry = 0;
       while (l1 || l2 || carry){
            carry += (l1? l1->val:0) + (l2? l2->val:0);
            cur = cur->next = new ListNode(carry % 10);
            carry/=10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
       }
       return l3->next;
    }
};