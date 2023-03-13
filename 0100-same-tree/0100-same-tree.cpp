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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //base case if roots null then return true.
        if(p==NULL && q==NULL){
            return true;
        }
        if(!p && q){
            return false;
        }
        if(p && !q){
            return false;
        }
        
        bool left = isSameTree(p -> left,q -> left);
        bool right = isSameTree(p -> right,q -> right);
        bool ans = p->val == q->val;
        
        if(left && right && ans){
            return true;
        }
        else{
            return false;
        }
    }
};