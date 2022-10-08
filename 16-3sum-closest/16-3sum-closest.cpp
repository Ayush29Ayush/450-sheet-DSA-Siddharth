//Ek element ko fix karo and aage ke do elements ko dhundho which will give sum closest to target

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int min_diff = INT_MAX;
        int ans = 0;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i<n; i++)
        {
            // fixing the first element 
            int first = nums[i];
            
            // now apply two pointer approach
            int start = i+1;
            int end = n-1;
            
            while(start<end)
            {
                int sum = 0;
                sum = first + nums[start] + nums[end];
                
                if(sum == target) // that means dono ko subtract karke 0 aa gaya, isse closest aur kuch nahi ho sakta
                {
                    return sum;
                }
                
                // yahan pointer ko aage piche karo
                if(sum > target)
                    end--;
                else if(first + nums[start] + nums[end] < target)
                    start++;
                
                // yahan agar koi diff mila jo min_diff se chota ahi toh usse update kardo
                if(abs(sum-target) < min_diff)
                {
                    min_diff  = abs(sum-target);
                    ans = sum;
                }    
            }
        }
        
        return ans;
    }
};