//
// Created by china on 2024/2/28.
//
// 题目大意为实现二叉搜索树的升序迭代器。
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
class BSTIterator {
public:
    queue<TreeNode *> nodeList;//二叉树中序遍历顺序
    BSTIterator(TreeNode* root) {
        inOrder(root);
    }
    void inOrder(TreeNode* root){//中序遍历二叉树
        if(root == nullptr)
            return;
        inOrder(root->left);
        nodeList.push(root);
        inOrder(root->right);
    }

    int next() {//依次取出二叉搜索树中序遍历节点
        int x = nodeList.front()->val;
        nodeList.pop();
        return x;
    }

    bool hasNext() {
        return !nodeList.empty();
    }
};