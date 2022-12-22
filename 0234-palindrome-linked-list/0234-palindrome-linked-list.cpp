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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //! Make a vector to store the LL values
        vector<int> arr;
        
        ListNode* temp = head;
        
        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        
        //! Now check whether the array is palindrome or not
        int start = 0;
        int end = arr.size()-1;
        
        while(start<=end)
        {
            if(arr[start]!=arr[end])
            {
                return false;
            }
            else
            {
                start++;
                end--;
            }
        }
        
        return true;
    }
};