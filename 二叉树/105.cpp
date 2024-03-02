//
// Created by china on 2024/2/21.
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
    TreeNode* traversal(vector<int>& preorder, int preorderBegin, int preorderEnd, vector<int>& inorder, int inorderBegin, int inorderEnd){
        if(preorderBegin == preorderEnd) return nullptr;//递归推出边界，前序子数组大小为0
        int rootValue = preorder[preorderBegin];
        TreeNode* root = new TreeNode(rootValue);//创建子树根节点

        if(preorderEnd - preorderBegin == 1) return root;//如果root是前序子数组中唯一一个节点，直接返回
        int index;//分割前序，中序子数组的下标
        for(index = inorderBegin;index<inorderEnd;index++){
            if(inorder[index] == rootValue) break;
        }
        //切割中序数组
        //中序左区间，左闭右开
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = index;
        //中序右区间
        int rightInorderBegin = index + 1;
        int rightInorderEnd = inorderEnd;

        //切割前序数组
        //前序左区间,左闭右开
        int leftPreorderBegin = preorderBegin + 1;
        int leftPreorderEnd = preorderBegin + 1 + index - inorderBegin; // 终止位置是起始位置加上中序左区间的大小size
        //前序右区间
        int rightPreorderBegin = preorderBegin + 1 + (index - inorderBegin);
        int rightPreorderEnd = preorderEnd;

        root->left = traversal(preorder,leftPreorderBegin, leftPreorderEnd, inorder,leftInorderBegin, leftInorderEnd);
        root->right = traversal(preorder,rightPreorderBegin, rightPreorderEnd, inorder,rightInorderBegin, rightInorderEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size() == 0 || preorder.size() ==0) return nullptr;
        //数组区间遵循左闭右开,
        return traversal(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};