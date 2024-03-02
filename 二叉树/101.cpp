//
// Created by china on 2024/2/21.
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
    bool isSameTree(TreeNode* left, TreeNode *right){
        if(left == nullptr || right == nullptr)
            return left == right;
        return left->val == right->val && isSameTree(left->left, right->right) && isSameTree(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->left, root->right);
    }
};