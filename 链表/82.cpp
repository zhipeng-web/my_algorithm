//
// Created by china on 2024/2/6.
//
#include "iostream"
#include "unordered_map"
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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int, int> hash;
        if(head == nullptr) return head;
        ListNode *dumpy = new ListNode(-256,head);
        ListNode *fast,*slow;
        fast = head;
        slow = dumpy;
        while (fast){
           hash[fast->val]++;
           fast = fast->next;
        }
        fast = head;
        while (fast){
            if(hash[fast->val] > 1){
                fast = fast->next;
                continue;
            }
            slow->next = fast;
            slow = fast;
            fast = fast->next;
        }
        slow->next = nullptr;
        return dumpy->next;
    }
};
