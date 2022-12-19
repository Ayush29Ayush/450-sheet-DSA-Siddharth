// sum_range -> (low, high) -> (max_element, sum of all element)
// TC -> O(nlog(sum))
// refer -> https://www.youtube.com/watch?v=bcAwHkL7A3A

class Solution {
public:
    int no_of_subarrays_with_max_sum_as_mid(vector<int>& nums,int mid)
    {
        int sum = 0;
        int count_subarray = 1;
        
        for(int i=0; i<nums.size(); i++)
        {
            // agar mid se aage nikal gaya addition, then reinitialize karna padega
            if(sum + nums[i] > mid)
            {
                sum = nums[i];
                count_subarray++;
            }
            else
                sum+=nums[i];
        }
        
        return count_subarray;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end()); // for max element of the array
        int high = accumulate(nums.begin(), nums.end(), 0); // for sum of all elements of the array, initially sum is 0
        int ans = 0;
        
        if(k==1)
            return high;
        if(k==nums.size())
            return low;
        
        while(low<=high)
        {
            int mid = low+(high-low)/2; // it will be the max possible limit
            int n = no_of_subarrays_with_max_sum_as_mid(nums,mid);
            if(n>k)
            {
                // you have taken a very low mid
                low = mid+1;
            }
            else
            {
                // else mein aa gaye means no. of subarrays is withing the m i.e n<=k
                ans = mid; // mid is a possible ans
                high = mid-1; // try to find a better ans 
            }
        }
        
        return ans;
    }
};