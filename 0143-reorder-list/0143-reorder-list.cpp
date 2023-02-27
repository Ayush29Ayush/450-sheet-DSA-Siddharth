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

//! Brute Approach
// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         vector<int> ans;
//         ListNode* temp = head;
        
//         while(temp!=NULL)
//         {
//             ans.push_back(temp->val);
//             temp = temp->next;
//         }
        
//         vector<int> reorder;
//         int start = 0, end = ans.size()-1;
        
//         while(true)
//         {
//             if(start<end)
//             {
//                 reorder.push_back(ans[start]);
//                 start++;
//                 reorder.push_back(ans[end]);
//                 end--;
//             }
//             else if(start==end)
//             {
//                 reorder.push_back(ans[start]);
//                 break;
//             }
//         }
        
//         // ab aage kya karu? actual head ko reorder vector ke saath kesse link karu?
//     }
// };


//! Optimised Approach 
// Ex-> head = [1,2,3,4,5]
// 1. LL ko middle se divide kar denge 2 parts mein
// 2. So it will become 1,2,3 and 4,5
// 3. Now reverse the 2nd part to 5,4
// 4. Now use merge sort types like 1 with 5, 2 with 4 and at last 3 alone
class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nxt=NULL;
        
        while(curr)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        
        //step 1 - using slow and fast pointer approach to find the mid of the list
        ListNode* slow=head;
        ListNode* fast=head->next;
        
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //step 2 - reverse the second half and split the List into two.
        ListNode* second=reverse(slow->next); // independent list second
        slow->next=NULL;
        ListNode* first=head; // independent list first
        
        //step 3 - merging the two list
        // second list can be shorter when LL size is odd
        while(second)
        {
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
    }
};
