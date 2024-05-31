//
// Created by china on 2024/5/29.
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
    int getDepth(TreeNode *root){
        if(root== nullptr) return 0;
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);

        if(root->left== nullptr && root->right!= nullptr){
            return rightDepth+1;
        }
        if(root->left!= nullptr && root->right== nullptr) return 1+leftDepth;
        return min(leftDepth,rightDepth) + 1;
    }
    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
};