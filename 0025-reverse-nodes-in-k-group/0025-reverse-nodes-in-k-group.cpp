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

// refer this if needed -> https://www.youtube.com/watch?v=fi2vh0nQLi0&t=902s

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // base cases
        if(k==1)
            return head;
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        
        // remaining size less than k hua toh reverse nahi ho sakta
        ListNode *temp = head;
        int size=0;
        
        while(temp!=NULL)
        {
            temp = temp->next;
            size++;
        }
        
        if(size<k)
            return head;
        
        //! Step1 : reverse first k nodes
        ListNode *aagekatracker = NULL;
        ListNode *curr = head;
        ListNode *prev = NULL;
        int count = 0;
        
        while(curr!=NULL && count<k)
        {
            aagekatracker = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = aagekatracker;
            count++;
        }
        
        //! Step2 : ab recursion aage ka solve kar dega
        if(aagekatracker!=NULL)
        {
            head->next = reverseKGroup(aagekatracker, k);
        }
        
        //! Step3 : return head of reversed Linked List
        return prev;
    }
};