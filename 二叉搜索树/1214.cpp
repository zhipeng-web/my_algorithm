//
// Created by china on 2024/7/1.
//
#include "iostream"
#include "unordered_map"
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
    unordered_map<int, int> record; //统计root1这棵树上num
    void dfs(TreeNode *root){
        if(root == nullptr) return;
        record[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        dfs(root1);
        queue<TreeNode*> nodes;
        nodes.push(root2);
        while (!nodes.empty()){
            auto item = nodes.front();
            nodes.pop();
            if(item->left) nodes.push(item->left);
            if(item->right) nodes.push(item->right);
            if(record[target - item->val] > 0) return true;
        }
        return false;
    }
};