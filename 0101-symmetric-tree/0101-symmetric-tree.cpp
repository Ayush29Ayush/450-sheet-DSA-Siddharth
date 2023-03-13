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


/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=lHLW1L8Qc5w
    Company Tags                : Amazon, Microsoft, Mentor (Siemens)
    Leetcode Link               : https://leetcode.com/problems/symmetric-tree/
*/

class Solution {
public:
    
    bool check(TreeNode* l, TreeNode* r) {
        // base case
        if(l == NULL && r == NULL)
            return true;
        if(l == NULL || r == NULL)
            return false;
        
        // if every condition for symmetric matches then return true else false
        if(l->val == r->val && check(l->left, r->right) && check(l->right, r->left))
            return true;
        
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        
        return check(root->left, root->right);
    }
};