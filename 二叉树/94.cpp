//
// Created by china on 2024/4/3.
//
#include "iostream"
#include "vector"
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

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        stack<TreeNode*> stack1;
        TreeNode* cur = root;
        while (cur != nullptr || !stack1.empty()){
            if (cur!= nullptr){ // 指针来访问节点，访问到最底层
                stack1.push(cur);// 将访问的节点放进栈
                cur = cur->left;//  左
            } else{
                cur = stack1.top(); // 从栈里弹出的数据，就是要处理的数据（放进ans数组里的数据）
                stack1.pop();
                answer.push_back(cur->val);//中
                cur=cur->right;// 右
            }
        }
        return answer;
    }
};