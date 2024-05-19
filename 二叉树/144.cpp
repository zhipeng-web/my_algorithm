//
// Created by china on 2024/5/19.
//
#include "vector"
#include "stack"
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x), left(left), right(right){}
};
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack1;
        vector<int> answer;
        if(root == nullptr){
            return answer;
        }
        stack1.push(root);
        while (!stack1.empty()){
            TreeNode* node = stack1.top();
            stack1.pop();
            answer.push_back(node->val);
            if(node->right) stack1.push(node->right);// 右（空节点不入栈)
            if(node->left) stack1.push(node->left);// 左（空节点不入栈）
        }
        return answer;
    }
};