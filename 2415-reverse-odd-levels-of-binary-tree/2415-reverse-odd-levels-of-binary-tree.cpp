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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q; 
        
        //Insert the root node which is at level=0 in the queue
        q.push(root); 
        int level=0; 
        
        while (!q.empty()) {
            vector<int> nums; 
            int n=q.size();
            vector<TreeNode*> nodes; 
            //Nodes will hold all the nodes of current level
            //Nums will hold their values 
            
            for (int i=0; i<n; i++){
                TreeNode* curr= q.front(); 
                q.pop();
                nums.push_back(curr->val); 
                nodes.push_back(curr); 
                if(curr->left) q.push(curr->left); 
                if(curr->right) q.push(curr->right);  
            }
            //If the level is odd, I will reverse the values and assign them to the TreeNodes using a for loop. 
            if(level%2){
                reverse(nums.begin(), nums.end()); 
                for (int i=0; i<nodes.size(); i++) {
                    TreeNode* curr= nodes[i]; 
                    curr->val= nums[i]; 
                }
            }
            //increase the level
            level++;
        }
        return root;
    }
};