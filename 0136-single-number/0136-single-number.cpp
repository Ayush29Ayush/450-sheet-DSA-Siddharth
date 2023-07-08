//! Solved using XOR operator
//! 2 same number ka XOR is 0 and at last 0^X = X. So you get the single number
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       int ans=0;
        
	   for(auto x:nums)
           ans^=x;
        
	   return ans;
    }
};