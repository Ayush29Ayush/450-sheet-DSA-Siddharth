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

//! Approach1(Brute) => if X is the element, search in the BST all the elements greater than X and sum them

//! Approach2(Optimized) => pehle rightmost pe chale jao and vahan se start karo updation, then go to left
//! See this DRY RUN for better understanding => https://www.youtube.com/watch?v=29D8XqP7nr8
class Solution {
public:
    int sum=0;
    
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL)
            return NULL;
        if(root!=NULL)
        {
            bstToGst(root->right);
            sum += root->val;
            root->val = sum;
            bstToGst(root->left);
        }
        
        return root;
    }
};