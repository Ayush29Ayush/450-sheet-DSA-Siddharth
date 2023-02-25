// refer this for dry run and explanation => https://www.youtube.com/watch?v=l_CFMVPKv2Q

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // will keep track of sub array elements in decreasing order
        vector<int> ans; // will strore the max element from each sub array
        
        // lets traverse the first sub array and if back is less than current, pop the back and insert the current
        for(int i=0; i<k; i++)
        {
            while(!dq.empty() && dq.back()<nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        // now since the deque is in decreasing order, the first element will be the max of that subarray
        ans.push_back(dq.front());
        
        for(int i=k; i<nums.size(); i++)
        {
            if(dq.front()==nums[i-k]) dq.pop_front();
            
            while(!dq.empty() && dq.back()<nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            ans.push_back(dq.front());
        }
        return ans;
    }
};