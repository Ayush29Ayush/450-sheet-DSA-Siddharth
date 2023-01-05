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

// refer STRIVER video => https://www.youtube.com/watch?v=EoAsWbO7sqg
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        
        if(root==NULL)
            return ans;
        
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;
            // traversal in queue using for loop
            for(int i=0; i<size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                // left and right node exist karte hai toh voh daal do
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
                // ab left right ka ho gaya, now node ki value daal do
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};