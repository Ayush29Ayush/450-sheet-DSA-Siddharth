//! refer this => https://www.youtube.com/watch?v=XjP2mQr98WQ
//! Since the question is related to subarray and sum, we will use PREFIX SUM
//! Do DRY RUN
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int count=0;
        int n = nums.size();
        unordered_map<int,int> mp;
        
        for(int i=0; i<n; i++)
        {
            // contiguous array ka sum lete jao har traversal pe
            sum += nums[i];
            
            
            //1. agar sum=k ho gaya toh ek subarray mil gaya so count++
            if(sum==k)
                count++;
            //3. agar sum-k mil gaya map mein means ek aur subarray mil gaya so uska freq add kardo count mein
            // like Y=X+k so Y-k=X 
            if(mp.find(sum-k)!=mp.end())
                count += mp[sum-k];
            
            
            //4. agar vahi sum phir kabhi aage mil gaya so update its freq
            if(mp.find(sum)!=mp.end())
                mp[sum]++;
            //2. jo bhi sum aaya usko map mein store karlo with its freq
            else
                mp[sum] = 1;
        }
        return count;
    }
};