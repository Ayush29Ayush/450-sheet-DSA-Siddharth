/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//! height-balanced binary tree have diff of height of left and right no more than 1. 
class Solution {
public:
    int func(TreeNode* root, bool &isSafe)
    {
        if(root==NULL) return 0;
        
        int left = func(root->left, isSafe)+1;
        int right = func(root->right, isSafe)+1;
        
        if(abs(left-right)>1)
            isSafe = false;
        
        return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) 
            return true;
        
        bool isSafe = true;
        int height = func(root, isSafe);
        
        return isSafe;
        
    }
};