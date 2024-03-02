//
// Created by china on 2024/2/28.
//
#include "stack"
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
    stack<TreeNode *> node_list;
    BSTIterator(TreeNode* root) {
        while (root){//将根节点和它的所有左节点放到栈中
            node_list.push(root);
            root = root->left;
        }
    }

    int next() {//取出节点时，如果它有右子树，则对右子树一路到底，把它和它的所有左节点放到栈中。
       TreeNode* node = node_list.top()->right;
       int x = node_list.top()->val;
       node_list.pop();
       while (node){
           node_list.push(node);
           node = node->left;
       }
       return x;
    }

    bool hasNext() {
        return !node_list.empty();
    }
};