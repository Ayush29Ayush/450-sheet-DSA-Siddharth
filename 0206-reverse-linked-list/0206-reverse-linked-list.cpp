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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* aage_ka_tracker = head;
        
        while(curr!=NULL)
        {
            // aage wale ka track pehle rakhlo
            aage_ka_tracker = curr -> next;
            // sabko ek ek piche point karana hai
            curr -> next = prev;
            
            // ab ek ek step aage badhado
            prev = curr;
            curr = aage_ka_tracker;
        }
        return prev;
    }
};