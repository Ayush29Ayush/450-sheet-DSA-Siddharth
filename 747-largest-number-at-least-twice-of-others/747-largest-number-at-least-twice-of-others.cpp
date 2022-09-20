class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxelement = INT_MIN;
        int index = 0;
        int n = nums.size();
        
        //! take out the max element and its index from the vector
        for(int i=0; i<n; i++)
        {
            if(nums[i]>maxelement)
            {
                maxelement = nums[i];
                index = i;
            }
        }
        //! To check maxelement greater than atleast twice of other elements
        // bool flag = false;
        int flag = 0;
        for(int i = 0; i<n; i++)
        {
            // check all the elements other than the maxelement
            if(nums[i] != maxelement)
            {
                // if maxlement is less than twice of any element, then game over
                // if(!(maxelement > 2*nums[i]))
                if(maxelement < 2*nums[i])
                {
                    // flag = true;
                    flag = 1;
                    break;
                }
            }
        }
        
        if(flag==1)
            return -1;
        else
            return index;
    }
};