//
// Created by china on 2024/3/2.
//
#include "iostream"
#include "queue"
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> answer;
        queue<TreeNode*> node_list;//层序遍历查二叉树，求每一层的平均值
        node_list.push(root);
        while (!node_list.empty()){
            int n = node_list.size();//确定每一层节点的个数
            double sum = 0;//每一层节点值的和
            for(int i=0;i<n;i++){
                TreeNode *node = node_list.front();
                node_list.pop();
                sum += node->val;
                if(node->left) node_list.push(node->left);
                if(node->right) node_list.push(node->right);
            }
            answer.push_back(sum / n);
        }
        return answer;

    }
};