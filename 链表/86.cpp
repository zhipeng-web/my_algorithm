//
// Created by china on 2024/2/7.
//
/*
 * 将链表拆分为两个链表，不改变顺序，一个存小于x的节点，一个存大于等于x的节点
 */
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
    ListNode* partition(ListNode* head, int x) {
       ListNode *cur = head;
       ListNode *dumpy = new ListNode(-300, head);//>x的链表哨兵节点
       ListNode *pre = dumpy;
       ListNode *dumpy_min = new ListNode();//<x的链表哨兵节点
       ListNode *min_cur = dumpy_min;
        while (cur!= nullptr){
            if(cur->val<x){
                pre->next = cur->next;
                cur->next = min_cur->next;
                min_cur->next = cur;
                min_cur = min_cur->next;
                cur = pre->next;
                continue;
            }
            cur = cur->next;
            pre = pre->next;
        }
        min_cur->next = dumpy->next;
        return dumpy_min->next;
    }
};