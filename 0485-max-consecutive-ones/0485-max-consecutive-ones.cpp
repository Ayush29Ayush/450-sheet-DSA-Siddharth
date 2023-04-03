class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = -1;
        int count = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==1)
            {
                count++;
            }
            else
            {
                // agar pichle se match nahi kara toh current count ki value ko store karlo ans mein and then reinitialize count to 1
                // agar present count is greater than prev count then ans ko update kardo using max so that jo max length ka substring hoga uska length store ho jaye
                ans = max(ans,count);
                count=0;
            }
        }
        // agar last ke kuch number same hai then else mein jayega hi nahi and ans will not get updated. So manually last mein karlo for safety
        // EX-> nums = [1,1,1,1,1,1]
        ans = max(ans,count);
        return ans;
    }
};