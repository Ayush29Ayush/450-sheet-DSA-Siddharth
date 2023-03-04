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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL) 
            return head;
        if(head -> next == NULL) 
            return head;
        
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        
        ListNode* temp = head;
        // vector<int> vec;
        set<int> s;
        
        while(temp!=NULL)
        {
            // vec.push_back(temp->val);
            s.insert(temp->val);
            temp = temp->next;
        }
        
        for(auto value : s)
        {
            ListNode* node = new ListNode(value);
            curr->next = node;
            curr = curr->next;
        }
        
        return ans->next;
        
    }
};