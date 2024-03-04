//
// Created by china on 2024/3/3.
//
#include "vector"
#include "iostream"
#include "queue"
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> answer;
        queue<TreeNode*> nodeList;
        nodeList.push(root);
        bool flag = true;//flag为false时，将每一层节点的顺序颠倒一下
        while (!nodeList.empty()){
            vector<int> temp;//每一层节点的值
            int n = nodeList.size();
            for(int i=0;i<n;i++){
                TreeNode* node = nodeList.front();
                temp.push_back(node->val);
                nodeList.pop();
                if(node->left) nodeList.push(node->left);
                if(node->right) nodeList.push(node->right);
            }
            if(flag){
                answer.push_back(temp);
            } else{
                reverse(temp.begin(), temp.end());
                answer.push_back(temp);
            }
            flag = !flag;
        }
        return answer;
    }
};