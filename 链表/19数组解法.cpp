//
// Created by china on 2024/2/5.
//
#include "iostream"
#include "vector"
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
        vector<ListNode*> assist;
        ListNode *cur = head;
        while (cur){
            assist.push_back(cur);
            cur = cur->next;
        }
        int num = assist.size();
        if(num == 1) return nullptr;
        if(n==1 && num>1){
            assist[num-2]->next = nullptr;
            return head;
        }
        if(n==num){
            head = head->next;
            return head;
        }
        assist[num - n - 1]->next = assist[num - n + 1];
        return head;
    }
};