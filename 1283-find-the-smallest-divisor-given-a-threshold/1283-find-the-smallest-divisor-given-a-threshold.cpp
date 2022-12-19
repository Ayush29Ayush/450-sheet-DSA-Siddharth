// Formula for remainder => (x%y) = x - int(x/y)*y

// Same as Koko eating Banana
// low = 1 and high = max(nums[i]);
class Solution {
public:
    int isPossible(vector<int>& nums, int mid, int threshold)
    {
        int res = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            // basically ceil value le rahe yahan
            // res += (nums[i]/mid)+((nums[i]%mid)!=0);     // ceil likhne ka approach 1
            res += (int)ceil(1.0*nums[i]/mid);              // ceil likhne ka approach 2
            // 1.0 multiply nahi karenge toh exact divisible walo ka bhi next integer de dega, jo ki galat ho jayega
            // ex-> 5/5 is 1 but bina 1.0 ke ans 2 de dega but 6/5 is 1 but ceil se ans 2 dega which is correct 
        }
        
        return res;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        // low and high are divisors
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = 0;
        
        while(low<=high)
        {
            int div_mid = low+(high-low)/2;
            
            int temp_threshold = isPossible(nums, div_mid, threshold);
            if(temp_threshold<=threshold)
            {
                // potential ans is the div_mid
                ans = div_mid;
                // but ho sakta hai ki isse chote pe bhi optimal solution mil jaye, so high = mid-1
                high = div_mid-1;
            }
            else
                low = div_mid+1;
        }
        
        return ans;
    }
};