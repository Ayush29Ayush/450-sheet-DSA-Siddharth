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

// Solution1 => Solved using Inorder Traversal and vector, TC->O(N) and SC->O(N)
// class Solution {
// public:
//     void inorder(TreeNode* root, vector<int> &arr) {
//         //base case
//         if(root==NULL)
//             return;
        
//         inorder(root->left, arr);
//         arr.push_back(root->val);
//         inorder(root->right, arr);
            
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> arr;
//         inorder(root, arr);
//         return arr[k-1];
//     }
// };

// Solution2 => Solved using Inorder Traversal and counting, TC->O(N) and SC->O(N)
class Solution {
private: 
    int res;
public:
    void inorder(TreeNode* root, int& k) {
        // base case
        if(root==NULL) return;
        
        //Left
        inorder(root->left, k);
        //Node
        --k;
        if(k==0)
            res = root->val;
        //Right
        inorder(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return res;
    }
};