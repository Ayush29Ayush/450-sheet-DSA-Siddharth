/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//! Approach1 : har element pe jaaki visited mark kardo so that jab next time jesse hi kisi visited node pe aao, samajh jaoge ki yahi hai starting point
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         unordered_map<ListNode*,bool> visited;
//         ListNode* temp = head;
        
//         while(temp!=NULL)
//         {
//             if(visited[temp]==true)
//                 return temp;
//             else
//                 visited[temp] = true;
            
//             temp=temp->next;
//         }
        
//         return NULL;
//     }
// };

//! Approach2 : using fast-slow pointer method
class Solution {
    public:
    ListNode* detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode *slow  = head;
        ListNode *fast  = head;
        ListNode *entry = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {                      // there is a cycle
                while(slow != entry) {               // found the entry location
                    slow  = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;                                 // there has no cycle
    }
};