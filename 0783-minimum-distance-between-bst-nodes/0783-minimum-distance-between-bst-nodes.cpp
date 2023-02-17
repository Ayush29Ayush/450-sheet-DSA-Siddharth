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

//! Inorder(LNR)=>sorted order vector
//! then just diff nikalna hai vector se minimum wala

//! TC->O(n) and SC->O(1)
class Solution {
    int result = INT_MAX;
    TreeNode* prev = NULL;
    
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        //LNR
        inorder(root->left);
        
        if(prev!=NULL)
            result = min(result,root->val - prev->val);
        prev = root;
        
        inorder(root->right);
    }
    
    public:
        int minDiffInBST(TreeNode* root) {
            inorder(root);
            return result;
        }
};