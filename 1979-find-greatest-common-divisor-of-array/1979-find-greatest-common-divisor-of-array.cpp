//! Applying Euclidean algorithm
// The idea is, GCD of two numbers doesn’t change if smaller number is subtracted from a bigger number. 
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        int gcd=0;
        
        while(maxi>0 && mini>0)
        {
            if(maxi>mini)
                maxi = maxi-mini; // maxi = maxi%mini;
            else
                mini = mini-maxi; // mini = mini-maxi;
        }
        
        if(maxi==0)
            return mini;
        
        return maxi;
    }
};