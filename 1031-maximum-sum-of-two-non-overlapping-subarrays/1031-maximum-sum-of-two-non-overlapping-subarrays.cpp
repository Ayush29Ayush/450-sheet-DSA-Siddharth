// refer this if needed => https://www.youtube.com/watch?v=8e6U4O5VUx0&t=24s

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int x, int y) {
        int n = nums.size();
        vector<int> dp1(n);
        vector<int> dp2(n);
        // sum ke andar hamesha current x size ke subarray ka sum rahega
        int sum = 0;
        
        // LEFT TO RIGHT i.e x size ke subarray ka sum kitna hoga
        // ith index tak x size ke subarray ka max sum
        for(int i=0; i<n; i++)
        {
            //i<x ka matlab hai ki abhi humne x size ke subarray ko consider nahi kiya hai
            if(i<x)
            {
                sum += nums[i];
                dp1[i] = sum;
            }
            else
            {
                // sliding window types new element daalo and window ke starting(left) walo ko hatate jao
                sum = (sum + nums[i]) - nums[i-x];
                // ab picha max sum aur abhi ka sum compare karke jo max hai voh store karate jao
                dp1[i] = max(sum, dp1[i-1]);
            }
        }
        
        sum = 0;
        
        // RIGHT TO LEFT
        for(int i = n-1; i>=0; i--)
        {
            // condition is that ( i >= n-y ) so (i+y>=n) laga diya. 
            if(i+y>=n)
            {
                sum += nums[i];
                dp2[i] = sum;
            }
            else
            {
                // sliding window types new element daalo and window ke ending(right) walo ko hatate jao
                sum = (sum + nums[i]) - nums[i+y];
                dp2[i] = max(sum, dp2[i+1]);
            }
        }
        
        int ans = 0;
        for(int i=x-1; i<n-y; i++)
        {
            // CASE1 : x length ka subarray left mein ayega aur y length ka subarray right mein ayega
            ans = max(ans, dp1[i] + dp2[i+1]);
        }
        
        
        // -------------------------------------------------------------------------------------------------------------
        //! CASE2 : y pehle and x baadmein
        //! so upar wale code mein bass x and y ko swap kardo
        
        
        // vector<int> dp1(n);
        // vector<int> dp2(n);
        // sum ke andar hamesha current x size ke subarray ka sum rahega
        sum = 0;
        
        // LEFT TO RIGHT i.e x size ke subarray ka sum kitna hoga
        // ith index tak x size ke subarray ka max sum
        for(int i=0; i<n; i++)
        {
            //i<x ka matlab hai ki abhi humne x size ke subarray ko consider nahi kiya hai
            if(i<y)
            {
                sum += nums[i];
                dp1[i] = sum;
            }
            else
            {
                // sliding window types new element daalo and window ke starting(left) walo ko hatate jao
                sum = (sum + nums[i]) - nums[i-y];
                // ab picha max sum aur abhi ka sum compare karke jo max hai voh store karate jao
                dp1[i] = max(sum, dp1[i-1]);
            }
        }
        
        sum = 0;
        
        // RIGHT TO LEFT
        for(int i = n-1; i>=0; i--)
        {
            // condition is that ( i >= n-y ) so (i+y>=n) laga diya. 
            if(i+x>=n)
            {
                sum += nums[i];
                dp2[i] = sum;
            }
            else
            {
                // sliding window types new element daalo and window ke ending(right) walo ko hatate jao
                sum = (sum + nums[i]) - nums[i+x];
                dp2[i] = max(sum, dp2[i+1]);
            }
        }
        
        
        for(int i=y-1; i<n-x; i++)
        {
            // CASE1 : x length ka subarray left mein ayega aur y length ka subarray right mein ayega
            ans = max(ans, dp1[i] + dp2[i+1]);
        }
        
        
        
        return ans;
    }
};