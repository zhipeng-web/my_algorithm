//
// Created by china on 2024/5/31.
//
#include "iostream"
#include "vector"
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
    int maxDepth = INT_MIN;
    int ans;
    void dfs(TreeNode* root, int depth){//后序遍历，确保先处理左节点
        if(root == nullptr) return;
        if(root->left){
            dfs(root->left, depth+1);
        }
        if(root->right){
            dfs(root->right, depth+1);
        }
        if(root->right == nullptr && root->left== nullptr){ //叶子节点，更新depth和ans
            if(depth>maxDepth){
                maxDepth = depth;
                ans = root->val;
                return;
            }
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> myQueue;
        vector<int> nums;
        myQueue.push(root);
        while (!myQueue.empty()){
            int n = myQueue.size();
            nums.push_back(myQueue.front()->val); //将每一层最左边入数组，遍历完成后，nums数组最后一个就是答案
            for (int i = 0; i < n; ++i) {
                auto node = myQueue.front();
                myQueue.pop();
                if(node->left) myQueue.push(node->left);
                if(node->right) myQueue.push(node->right);
            }
        }
        return nums.back();
    }
};