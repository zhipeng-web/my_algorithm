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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> answer;
        queue<TreeNode *> node_list;
        node_list.push(root);
        while (!node_list.empty()){
            int n = node_list.size();
            vector<int> nums;//每一层节点值
            for(int i=0;i<n;i++){
                TreeNode* node = node_list.front();
                node_list.pop();
                nums.push_back(node->val);
                if(node->left) node_list.push(node->left);
                if(node->right) node_list.push(node->right);
            }
            answer.push_back(nums);
        }
        return answer;
    }
};