//
// Created by china on 2024/2/7.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head== nullptr)
            return head;
        ListNode *cur = head;
        int n = 0;//记录链表长度
        while (cur->next){
            cur = cur->next;
            n++;
        }
        n++;
        k = k % n;//确定每一个元素需要后移多少步
        cur->next = head;//链表收尾相连
        ListNode *fast=head, *slow = head;//快慢指针，
        while (k){
            fast = fast->next;//快指针先行k步,当fast再次到达头节点时，slow为新的头节点，此时断开即可
            k--;
        }
        while (fast!=head){
            fast = fast->next;
            slow = slow->next;
            cur = cur->next;//cur为slow前驱节点
        }
        cur->next = nullptr;
        return slow;
    }
};