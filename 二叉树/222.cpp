//
// Created by china on 2024/2/28.
//
#include "queue"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode *> node_queue;
        int answer = 0;
        node_queue.push(root);
        while (!node_queue.empty()){
            TreeNode* node = node_queue.front();
            node_queue.pop();
            answer++;
            if(node->left) node_queue.push(node->left);
            if(node->right) node_queue.push(node->right);
        }
        return answer;
    }
};