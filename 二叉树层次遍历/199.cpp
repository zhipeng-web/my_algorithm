//
// Created by china on 2024/3/3.
//
#include "vector"
#include "iostream"
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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> nodeList;
        vector<int> answer;
        if(root == nullptr) return {};
        nodeList.push(root);
        while (!nodeList.empty()){
            int n = nodeList.size();
            vector<int> temp;//存储每一层的节点，从左到右顺序
            for(int i=0;i<n;i++){
                TreeNode* node = nodeList.front();
                temp.push_back(node->val);
                nodeList.pop();
                if(node->left) nodeList.push(node->left);
                if(node->right) nodeList.push(node->right);
            }
            answer.push_back(temp.back());//将每一层最右边元素存储
        }
        return answer;
    }
};