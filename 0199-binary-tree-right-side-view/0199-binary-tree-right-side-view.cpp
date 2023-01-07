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
//! STRIVER VIDEO => https://www.youtube.com/watch?v=KV4mRzTjlAk
//! Using Reverse PreOrder Traversal (Recursive) but with NRL, not NLR
class Solution {
public:
    void RightView(TreeNode* root, int level, vector<int>&ans)
    {
        if(root==NULL)
            return;
        
        if(level == ans.size())
            ans.push_back(root->val);
        
        RightView(root->right, level+1, ans);
        RightView(root->left, level+1, ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        RightView(root, 0, ans);
        
        return ans;
    }
};