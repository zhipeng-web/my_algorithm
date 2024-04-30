//
// Created by china on 2024/3/6.
//
#include "vector"
#include "unordered_map"
#include "queue"
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    unordered_map<int,Node*> hash;
    Node* cloneGraph(Node* node) { //递归创建节点
        if(node == nullptr) return node;
        Node *copy = nullptr;
        if(hash.count(node->val)){//节点已经创建，直接返回
            copy = hash[node->val];
            return copy;
        } else{
            copy = new Node(node->val);
            hash[copy->val] = copy;
        }
        for(auto it:node->neighbors){//构造节点的邻居阶段
            Node * neighbor = cloneGraph(it);
            copy->neighbors.push_back(neighbor);
        }
        return copy;
    }
};