//
// Created by china on 2024/2/3.
//
#include "iostream"
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
        ListNode *p = list1, *q = list2;
        ListNode *answer = new ListNode();
        ListNode *cur = answer;
        while (p != nullptr & q != nullptr){
            int a = p->val, b = q->val;
            if(a<b){
                cur->next = p;
                p = p->next;
                cur = cur->next;
            } else{
                cur->next = q;
                q=q->next;
                cur = cur->next;
            }
        }
        while (p){
            cur->next = p;
            p=p->next;
            cur = cur->next;
        }
        while (q){
            cur->next=q;
            q=q->next;
            cur = cur->next;
        }
        return answer->next;
    }
};