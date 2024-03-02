//
// Created by china on 2024/2/28.
//
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
    bool exists(TreeNode* root, int level, int k){//判断二叉树中是否存在具有给定索引值的节点
        int bits = 1 << (level - 1);
        TreeNode* node = root;
        while (node!= nullptr && bits>0){
            if(!(bits & k)){//当前位为0，左子树移动0
                node = node->left;
            } else{
                node = node->right;
            }
            bits >>= 1;
        }
        return node != nullptr;
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int level = 0;
        TreeNode* node = root;
        while (node->left){
            level++;
            node = node->left;
        }
        int low = 1 << level, high = (1 <<(level + 1))-1;
        while (low < high){
            int mid = (high - low + 1)/2 + low;
            if(exists(root, level, mid)){
                low = mid;
            } else{
                high = mid - 1;
            }
        }
        return low;
    }
};