//
// Created by china on 2024/2/22.
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
    TreeNode* traversal(vector<int>& postorder, int postorderBegin, int postorderEnd, vector<int>& inorder, int inorderBegin, int inorderEnd){
        if(postorderBegin == postorderEnd) return nullptr;
        int rootValue = postorder[postorderEnd - 1];
        TreeNode* root = new TreeNode(rootValue); //创建根节点·
        if(postorderEnd -1 == postorderBegin) return root;

        int index;//根节点在中序数组中的位置
        for(index = inorderBegin;index<inorderEnd;index++){
            if(inorder[index] == rootValue) break;
        }

        //分割中序数组,根节点左子树
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = index;

        //分割中序数组,根节点右子树
        int rightInorderBegin = index + 1;
        int rightInorderEnd = inorderEnd;

        //分割后序数组，根节点左子树
        int leftPostorderBegin = postorderBegin;
        int leftPostorderEnd = postorderBegin + index - inorderBegin; //  终止位置是 需要加上 中序区间的大小size

        //分割后序数组，根节点右子树
        int rightPostorderBegin = postorderBegin + index - inorderBegin;
        int rightPostorderEnd = postorderEnd - 1;//排除最后一个节点，因为它已经是根节点了

        root->left = traversal(postorder, leftPostorderBegin, leftPostorderEnd, inorder, leftInorderBegin, leftInorderEnd);
        root->right = traversal(postorder, rightPostorderBegin, rightPostorderEnd, inorder, rightInorderBegin, rightInorderEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return traversal(postorder,0,postorder.size() ,inorder,0, inorder.size());
    }
};