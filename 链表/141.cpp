//
// Created by china on 2024/2/2.
//
#include "iostream"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *low = head;
        while (fast!= nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            low = low->next;
            if(fast == low) return true;
        }
        return false;
    }
};