//
// Created by china on 2024/4/3.
//
#include "iostream"
#include "vector"
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
    vector<int> answer;
    void dfs(TreeNode *root){
        if(root == nullptr)
            return;
        dfs(root->left);
        answer.push_back(root->val);
        dfs(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return {};
        dfs(root);
        return answer;
    }
};