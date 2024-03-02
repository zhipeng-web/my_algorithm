//
// Created by china on 2024/2/29.
//
#include "unordered_map"
#include "vector"
#include "queue"
#include "algorithm"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> p_parents, q_parents;//每一个节点的祖先序列,从节点到根节点顺序
        unordered_map<TreeNode*, TreeNode*> node_parents;//每一个节点的父节点,root的父节点为nullptr
        node_parents[root] = nullptr;
        queue<TreeNode *> my_queue;
        my_queue.push(root);
        while (!my_queue.empty()){//层序遍历二叉树，寻找每一个节点的父节点
            TreeNode *node = my_queue.front();
            my_queue.pop();
            if(node->left){
                node_parents[node->left] = node;
                my_queue.push(node->left);
            }
            if(node->right){
                node_parents[node->right] = node;
                my_queue.push(node->right);
            }
        }
        while (p){//构造p的祖先序列
            p_parents.push_back(p);
            p = node_parents[p];
        }
        while (q){//构造q的祖先序列
            q_parents.push_back(q);
            q = node_parents[q];
        }
        for(auto it : p_parents){//查找公共子节点
            if(find(q_parents.begin(), q_parents.end(), it) != q_parents.end())
                return it;
        }
        return nullptr;
    }
};