//
// Created by china on 2024/2/25.
//
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        //判断一个节点是否为叶子节点，需要查看左右子树是否都为空
        //判断root是否为叶子节点
        if(root->left == nullptr && root->right == nullptr)
            return root->val == targetSum;
        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};