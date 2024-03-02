//
// Created by china on 2024/3/2.
//
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
    int answer = INT_MIN;
    int dfs(TreeNode *root){
        if(root == nullptr)
            return 0;//当前节点为叶子节点时，子链表和为0
        int left_val = dfs(root->left);//计算左子树的最大链表和
        int right_val = dfs(root->right);//计算右子树的最大链表和
        answer = max(answer, left_val + right_val + root->val);//将两条链表拼接成路径
        return max(0, root->val + max(left_val, right_val));// 当前子树最大链和
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return answer;
    }
};