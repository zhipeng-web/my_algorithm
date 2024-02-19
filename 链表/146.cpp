//
// Created by china on 2024/2/16.
//
#include "iostream"
#include "unordered_map"
using namespace std;
class Node{
public:
    int key,value;
    Node *prev, *next;
    Node(int k=0, int v=0) : key(k), value(v){}
};
class LRUCache {
private:
    int capacity; //容量
    Node *dumpy; //哨兵节点
    unordered_map<int, Node*> hash;

    //删除节点
    void remove(Node *x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

    //在头节点插入节点
    void push_front(Node *x){
        x->prev = dumpy;
        x->next = dumpy->next;
        x->next->prev = x;
        x->prev->next = x;
    }

    Node *get_node(int k){
        auto it = hash.find(k);
        if(it == hash.end()) //节点不存在
            return nullptr;
        auto node = it->second;
        remove(node);
        push_front(node);
        return node;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        dumpy = new Node();
        dumpy->prev = dumpy;
        dumpy->next = dumpy;
    }

    int get(int key) {
        auto node = get_node(key);
        return node ? node->value : -1;
    }

    void put(int key, int value) {
       auto it = get_node(key);//判断节点是否存在
       if(it){
           it->value = value;
           return;
       }
       Node* node = new Node(key, value);
       hash[key] = node;//新节点添加到hash表中
       push_front(node);
       if(hash.size() > capacity){//判断是否超出容量,若超出，则移除最后一个节点
           auto back_node = dumpy->prev;
           hash.erase(back_node->key);
           remove(back_node);
           delete back_node;
       }
    }
};
