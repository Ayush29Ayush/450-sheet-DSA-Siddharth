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
    YOUTUBE VIDEO FOR THIS Qn : BFS - https://youtu.be/08e5EBHoXxE
                                DFS - https://youtu.be/5zyG8Nw9V78
                                
    Company Tags                 : Amazon, Meta
    Leetcode Link                : https://leetcode.com/problems/check-completeness-of-a-binary-tree/
*/

//Approach-1 : BFS
// Level Order karte jao and har node se pucho ki past mein NULL dekha hai kya? because Level Order mein left to right jaate hai in that level
// Agar NULL aa gaya kahi toh uske baad koi node nahi aana chahiye, if it does then its not a Complete Binary Tree
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        //Using BFS(Level Order)
        
        queue<TreeNode*> que;
        
        que.push(root);
        
        bool past = false; //kya aapne past me NULL node dekha hai ?
        
        while(!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            
            if(node == NULL) 
            {
                past = true;
            } 
            // agar node NULL nahi hai toh usse pucho ki kya past mein NULL dekha hai? If yes toh return false varna push left and right node as in Level Order
            else if(node != NULL) 
            {
                if(past == true) 
                {
                    return false;
                }
                
                que.push(node->left);
                que.push(node->right);
            }
        }
        
        return true;
    }
};