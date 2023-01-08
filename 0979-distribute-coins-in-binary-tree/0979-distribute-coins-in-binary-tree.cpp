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

//! refer this video => https://www.youtube.com/watch?v=MvLEIQv4E6s
// Do DRY RUN
class Solution {
public:
    int count=0;
    int func(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        int l=func(root->left);
        int r=func(root->right);
        
        count+=abs(l)+abs(r);
        
        return (l+r+root->val-1);
    }
    
    int distributeCoins(TreeNode* root) {
        // int ans = func(root);
        // return ans;
        func(root);
        return count;
    }
};