// https://leetcode.com/problems/last-stone-weight/discuss/1921100/Simple-easy-c%2B%2B-solution
// https://www.cplusplus.com/reference/queue/priority_queue/

class Solution {
public:
     int lastStoneWeight(vector<int>& stones) 
    {
         // This is a max-heap
         // By default, a priority queue in C++ is a max-heap, meaning that the element with the highest priority (i.e. the largest element) is always at the top of the queue.
        priority_queue<int> pq(stones.begin(),stones.end());
        while(pq.size()>1)
        {
            int y=pq.top();
            pq.pop();
            int x=pq.top();
            pq.pop();
            if(x!=y) pq.push(y-x);
        }
        return pq.empty()? 0 : pq.top();
    }
};