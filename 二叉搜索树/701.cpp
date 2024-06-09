//
// Created by china on 2024/6/5.
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
       if(root == nullptr) return root;
       TreeNode* head = root;
       if(root->val>val){
           if(root->left == nullptr){
               TreeNode* node = new TreeNode(val);
               root->left = node;
           } else{
               insertIntoBST(root->left, val);
           }
       } else{
            if(root->right == nullptr){
                TreeNode* node = new TreeNode(val);
                root->right = node;
            } else{
                insertIntoBST(root->right, val);
            }
       }
       return head;
    }
};