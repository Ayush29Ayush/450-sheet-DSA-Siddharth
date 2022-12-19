//! Approach1 -> Use STL
// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int ans = *min_element(nums.begin(), nums.end());
//         return ans;
//     }
// };

//! Approach2 -> Use Binary Search
// 2nd half ka 1st element will be the minimum element
// 2nd half ka 1st element 1st half ke end element se chota hoga
// 1st half ka last element 2nd half ke 1st element se bada hoga

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        
        if(nums.size()==1)
            return nums[0];
        
        // agar array bilkul rotate hi nahi hua hai then pehla element is the min
        while(nums[low]<nums[high])
            return nums[0];
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            // ans ka criteria
            if(nums[mid]>nums[mid+1])
                return nums[mid+1];
            
            else if(nums[mid]<nums[mid-1])
                return nums[mid];
            
            else if(nums[mid]>nums[mid+1])
                return nums[mid+1];
            
            else if(nums[low]<=nums[mid])
                low = mid+1;
            
            else if(nums[mid]<=nums[high])
                high = mid-1;
        }
        
        return -1;
    }
};