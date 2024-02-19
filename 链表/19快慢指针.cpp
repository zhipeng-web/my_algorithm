//
// Created by china on 2024/2/5.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dumpy = new ListNode(0, head);
        ListNode *fast, *slow;
        fast = slow = dumpy;
        while (n>0){
            n--;
            fast = fast->next;
        }
        while (fast!= nullptr && fast->next!= nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dumpy->next;
    }
};