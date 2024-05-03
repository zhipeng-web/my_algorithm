//
// Created by china on 2024/5/3.
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *dumpy = new ListNode();
        dumpy->next = head;
        ListNode *cur = dumpy;
        ListNode *slow ;
        ListNode *fast ;
        while (cur->next != nullptr && cur->next->next != nullptr){
            ListNode* tmp = cur->next; // 记录临时节点
            ListNode* tmp1 = cur->next->next->next; // 记录临时节点

            cur->next = cur->next->next;    // 步骤一
            cur->next->next = tmp;          // 步骤二
            cur->next->next->next = tmp1;   // 步骤三


            cur->next->next->next = tmp1;
            cur = cur->next->next;
        }
        return dumpy->next;
    }
};