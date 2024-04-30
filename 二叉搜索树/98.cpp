//
// Created by china on 2024/3/4.
//
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
    vector<int> nodeVal;
    //每一颗二叉树的中序遍历是唯一的，判断一棵二叉树是否是二叉搜索树，只需要判断其中序遍历是否是递增的
    void inOrder(TreeNode* root){ //pre 代表前一个节点
        if(root == nullptr) return;
        inOrder(root->left);
        nodeVal.push_back(root->val);
        inOrder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        for(int i=0;i<nodeVal.size()-1;i++){
            if(nodeVal[i] >= nodeVal[i + 1])
                return false;
        }
        return true;
    }
};