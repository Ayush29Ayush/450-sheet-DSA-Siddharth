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
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        
        //edge case
        if(left==0) return right+1; // because if left=0, then usko compare karne ka koi fayda nahi
        if(right==0) return left+1; // because if right=0, then usko compare karne ka koi fayda nahi
        
        return min(left,right)+1;
    }
};