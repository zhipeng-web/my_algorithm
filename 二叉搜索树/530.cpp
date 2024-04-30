//
// Created by china on 2024/3/4.
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
    vector<int> nodeVal;
    void inOrder(TreeNode* root){//中序遍历二叉搜索树，节点顺序为递增
        if(root == nullptr) return;
        inOrder(root->left);
        nodeVal.push_back(root->val);
        inOrder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        int answer = INT_MAX;
        inOrder(root);
        for(int i=1;i<nodeVal.size();i++){
            answer = min(answer, nodeVal[i] - nodeVal[i-1]);
        }
        return answer;
    }
};