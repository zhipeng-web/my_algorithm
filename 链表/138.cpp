//
// Created by china on 2024/2/3.
//
#include "iostream"
#include "unordered_map"
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    unordered_map<Node*, Node*> node_map;
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        if(!node_map.count(head)){
            Node *temp = new Node(head->val);
            node_map[head] = temp;
            temp->next = copyRandomList(head->next);
            temp->random = copyRandomList(head->random);
        }
        return node_map[head];
    }
};