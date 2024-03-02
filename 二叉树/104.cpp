//
// Created by china on 2024/2/19.
//
#include "iostream"
#include "algorithm"
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
    int maxDepth(TreeNode* root) {
        if(root){ //递归解法，root不为null，返回左右子树深度较大的一个 + 1
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        }
        return 0;
    }
};