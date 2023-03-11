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

// https://www.youtube.com/watch?v=HdR8Aeq_TkU

// we can observe that the root is always at the middle of the array.
// all the elements to the left are the left child of the root and all the elements to the right are the right child of the root.
class Solution {
public:
    TreeNode* ArrToBST(vector<int> nums, int start, int end) {
        if(start>end)
            return NULL;
        
        int midpoint = start + (end-start)/2;
        
        TreeNode* root = new TreeNode(nums[midpoint]);
        
        root->left = ArrToBST(nums, start, midpoint-1);
        root->right = ArrToBST(nums, midpoint+1, end);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        
        return ArrToBST(nums, 0,nums.size()-1);
    }
};