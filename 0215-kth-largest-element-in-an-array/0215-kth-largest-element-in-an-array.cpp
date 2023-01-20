// https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/2180777/C%2B%2B-solution-oror-Simple-oror-Optimized-Solution-oror-Sorting

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
        
//         return nums[nums.size()-k];
//     }
// };

//! refer -> https://youtu.be/_9F2VgZcvdw?t=1096
//! If Smallest element bola hota toh MAX_HEAP use karte
//! Largest element bolz toh MIN_HEAP use kiya
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int r = nums.size()-1;
        
        //! step1
        for(int i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }
        
        //! step2
        for(int i = k; i <= r; i++)
        {
            if(nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        //! step3
        int ans = pq.top();
        return ans;
    }
};