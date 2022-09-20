class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        
        // calc prefix vector
        int num1 = 1;
        prefix[0] = 1;
        for(int i = 1; i<n; i++)
        {
            num1 = num1*nums[i-1];
            prefix[i] = num1;
        }
        
        // calc suffix vector
        int num2 = 1;
        suffix[n-1] = 1;
        for(int i = n-2; i>=0; i--)
        {
            num2 = num2*nums[i+1];
            suffix[i] = num2;
        }
        
        // now multiplying prefix[i] and suffix[i] to store product of array except self.
        for(int i=0;i<n;i++){
            nums[i] = prefix[i]*suffix[i];
        }
        return nums;
    }
};