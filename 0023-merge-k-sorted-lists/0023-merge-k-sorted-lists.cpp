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

//! Approach1 : Using vectors to store elements and sort and return ans LL          TC -> O(N*K)
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         int k = lists.size(); // taking size of the list
//         if(k == 0) // if size is zero
//             return NULL; // simply return NULL
        
//         // making a vector pair where first contain value and second contain node
//         vector<pair<int, ListNode*>> arr; 
        
//         for(int i = 0; i < k; i++) // traverse all over the list
//         {
//             ListNode* curr_list = lists[i]; // extracting current linked list
            
//             while(curr_list != NULL) // while current linked list is NOT NULL
//             {
//                 arr.push_back({curr_list -> val, curr_list}); // push into vector
//                 curr_list = curr_list -> next;
//             }
//         }
        
//         // this does not gurantee that k is zero, 
//         // suppose an array like this [[],[],[],],here k = 3 and size of array is 0
//         if(arr.size() == 0) // if their is no element i.e zero element
//             return NULL;
        
//         sort(arr.begin(), arr.end()); // sort the vector on the basis of values
        
//         // start making links b/w the elements of vector
//         for(int i = 0; i < arr.size() - 1; i++)
//         {
//             arr[i].second -> next = arr[i + 1].second;
//         }
        
//         // in the next of last node put NULL
//         arr[arr.size() - 1].second -> next = NULL;
        
//         return arr[0].second; // return first node of the vector
//     }
// };

//! Approach2 : Using Merge 2 sorted LL logic, pehle 2 ko sort karo and uske ans ko 3rd wale ke saath          TC -> O(N*K)
// class Solution {
//     public ListNode mergeKLists(ListNode[] lists) {
//         if (lists.length == 0)
//             return null;
//         ListNode merged = null;
//         for (ListNode head : lists) {
//             merged = mergeTwoLists(merged, head);
//         }
//         return merged;
//     }
    
//     public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
//         if (l1 == null)
//             return l2;
//         if (l2 == null)
//             return l1;
//         if (l1.val < l2.val) {
//             l1.next = mergeTwoLists(l1.next, l2);
//             return l1;
//         }
//         else {
//             l2.next = mergeTwoLists(l1, l2.next);
//             return l2;
//         }
//     }
// }

//! Approach3 : CodeHelp wala MinHeap code but theek se samajh nahi aaya              Approach4 jessa hi tha CodeHelp ka code bhi

//! Approach4: Using MinHeap            TC-> O(nLogk)     SC-> O(k)             // https://www.youtube.com/watch?v=u8LQt_iUKps&t=114s
class mycompare{
	public:
    // isse ke vajah se minheap mein ascending order mein rahenge
	bool operator()(const ListNode* a,const ListNode* b){
        return (a->val>b->val);
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        // Initialize a MinHeap for LL
        priority_queue<ListNode*, vector<ListNode*>, mycompare> minheap;
        // priority_queue<ListNode*, vector<ListNode*>, greater<ListNode*>> minheap;           // yeh kaam nahi karega, minheap upar wale logic se hi banana padga
        
        // TEST CASE -> lists = [[1,4,5],[1,3,4],[2,6]]
        
        // now we are going to each LL inside the vector and if the head is not NULL then push it to the minheap
        for(int i=0; i<lists.size(); i++)
        {
            if(lists[i]!=NULL)
                minheap.push(lists[i]);
        }
        
        // pehle minheap mein honge => 1,1,2
        
        // ab LL banao
        while(!minheap.empty())
        {
            auto least = minheap.top();
            minheap.pop();
            
            temp->next = least; // temp ke next pe daalo
            temp = temp->next; // temp ko aage badhado
            
            // ek 1 lag gaya so uss 1 ke baad ka element ab minheap mein push hoga taaki phir 3 elements ko minheap order mein store kar sake
            if(least->next!=NULL)
                minheap.push(least->next);
        }
        
        return head->next;
    }
};
