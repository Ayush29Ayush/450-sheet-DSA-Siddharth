// refer this if needed => https://www.youtube.com/watch?v=GbJh0MjUa5U
// pre requisite => https://leetcode.com/problems/maximum-subarray/
class Solution {
public: 
    int maxProduct(vector<int>& nums) {
        int prod = 1;
        int maximum_prod = INT_MIN;
        
        // Ex -> [6,-3,-10,0,2] will give output = 180. This approach follows left to right traversal
        for(auto i : nums)
        {
            prod = prod * i;
            maximum_prod = max(maximum_prod, prod);
            
            if(prod == 0)
                prod = 1;
        }
        // but according to our logic , if we take [-8,5,3,1,6] will give output = -8 which is not the correct output, output should be 5x3x1x6=90
        // for such cases, it is imp to also traverse from right to left and find out the max product
        
        int n = nums.size();
        prod = 1;
        for(int i = n-1; i>=0; i--)
        {
            prod = prod * nums[i];
            maximum_prod = max(maximum_prod, prod);
            
            if(prod == 0)
                prod = 1;
        }
        
        return maximum_prod;
    }
};