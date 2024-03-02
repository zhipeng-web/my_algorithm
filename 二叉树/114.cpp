//
// Created by china on 2024/2/25.
//
#include "iostream"
#include "vector"
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
    vector<TreeNode *> node_list;
    void VLR(TreeNode* root){//先序遍历二叉树
        if(root == nullptr) return;
        node_list.push_back(root);//按照先序遍历顺序，将节点保存下来
        if(root->left) VLR(root->left);
        if(root->right) VLR(root->right);
    }
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        VLR(root);
        for(int i=0;i<node_list.size()-1;i++){//将节点左指针设置为nullptr,右指针设置为下一个节点
            node_list[i]->left = nullptr;
            node_list[i]->right = node_list[i+1];
        }
        node_list.back()->left = nullptr;
    }
};