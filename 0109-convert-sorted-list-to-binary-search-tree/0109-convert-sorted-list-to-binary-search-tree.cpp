/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* createBST(vector<int>& nums, int l, int r)
    {
        if(l<=r)
        {
            int mid = (l+r)/2;
            TreeNode* root = new TreeNode(nums[mid]);

            root->left = createBST(nums, l, mid-1);
            root->right = createBST(nums, mid+1, r);

            return root;
        }

        return NULL;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;

        //Storing the LinkedList in a vector
        vector<int> nums;

        while(head!=NULL)
        {
            nums.push_back(head->val);
            head = head->next;
        }

        //Calling createBST() & returning the root of created tree.
        return createBST(nums, 0, nums.size()-1);
    }
};