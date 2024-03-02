//
// Created by china on 2024/2/27.
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
    vector<int> nums;
    void dfs(TreeNode* root, int val){//深度遍历二叉树，并记录每一条从根节点到叶子节点的路径
        if(root == nullptr) return;
        if(root->left == nullptr && root->right== nullptr){
            nums.push_back(val * 10 + root->val);
            return;
        }
        dfs(root->left, val * 10 + root->val);
        dfs(root->right, val * 10 + root->val);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        int sum = 0;
        for(auto it = nums.begin();it!=nums.end();it++){
            sum += *it;
        }
        return sum;
    }
};