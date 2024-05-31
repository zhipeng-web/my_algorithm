//
// Created by china on 2024/5/31.
//
#include "iostream"
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
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 0;//当前节点为空，或者为叶子节点，则左叶子节点不存在，返回0

        int leftValue = dfs(root->left);
        if(root->left && root->left->left == nullptr && root->left->right == nullptr){
            leftValue = root->left->val;
        }
        int rightValue = dfs(root->right);
        return leftValue + rightValue;

    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;
        return dfs(root);
    }
};