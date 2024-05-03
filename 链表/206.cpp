//
// Created by china on 2024/5/3.
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
    ListNode* reverseList(ListNode* head) {
        ListNode* dumpy = new ListNode();
        while (head){
            ListNode *temp = head->next;
            head->next = dumpy->next;
            dumpy->next = head;
            head = temp;
        }
        return dumpy->next;
    }
};