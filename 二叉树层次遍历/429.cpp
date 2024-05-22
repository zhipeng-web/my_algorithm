//
// Created by china on 2024/5/22.
//
#include "vector"
#include "queue"
#include "algorithm"
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == nullptr){
            return ans;
        }
        queue<Node*> nodes;
        nodes.push(root);
        while (nodes.size()>0){
            int n = nodes.size();
            vector<int> nums;
            for (int i = 0; i < n; ++i) {
                auto node = nodes.front();
                nodes.pop();
                nums.push_back(node->val);
                for (int j = 0; j < node->children.size(); ++j) {
                    nodes.push(node->children[j]);
                }
            }
            ans.push_back(nums);
        }
        return ans;
    }
};