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

//! refer this if needed => https://leetcode.com/problems/sum-root-to-leaf-numbers/discuss/1555932/C%2B%2BRecursive-and-Iterative-Simple-explanation-or-100-faster-or-O(N)
//! PREORDER => NLR
class Solution {
public:
    void findSum(TreeNode* root, int number ,int &ans){
        if(root==NULL){
            return;
        }
        // keep forming a number
        // number=number*10+root->val;
        number=number*10+root->val;
        // when you reach the last node, that means the number has been formed. So add it to the total.
        if(root->left==NULL and root->right==NULL){
            ans+=number;
        }
        findSum(root->left,number,ans);
        findSum(root->right,number,ans);
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        //Output
        int ans=0;
        findSum(root,0,ans);
        return ans;
    }
};