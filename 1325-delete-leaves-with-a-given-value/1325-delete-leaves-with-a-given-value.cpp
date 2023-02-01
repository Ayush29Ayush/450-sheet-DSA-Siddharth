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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==NULL)
            return NULL;
        //! POST ORDER se kiya yeh solve => LRN
        
        // root ka left aur right re-assign hoga, agar leaf hai aur target mil gaya toh ab NULL pe point karega whivh means leaf node ab nahi raha
        // agar essa nahi hai toh jo node tha vahi re-assign ho jayega i.e return root
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        
        if(root->left==NULL && root->right==NULL && root->val==target)
            return NULL;
        else
            return root;
    }
};