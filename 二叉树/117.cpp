//
// Created by china on 2024/2/24.
//
#include "queue"
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        queue<Node*> node_queue;
        node_queue.push(root);
        while (!node_queue.empty()){
            int n = node_queue.size();
            Node *pre = new Node();//每一个节点的前一个节点，第一个节点没有前置节点，所以初始化一个哨兵节点
            for(int i=0;i<n;i++){
                auto node = node_queue.front();//取队列头节点
                node_queue.pop();
                if(node->left) node_queue.push(node->left);
                if(node->right) node_queue.push(node->right);
                pre->next = node;
                pre = node;
            }
        }
        return root;
    }
};