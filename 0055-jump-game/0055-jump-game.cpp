class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int index = n-1;
        
        // for easy approach, we will start from end and go right to left (n-1 -> 0)
        // it is same as going from start to end i.e left to right (0 -> n-1)
        // dry run karke dekh lena ache se sab samajh aa jayega
        for(int i=n-1; i>=0; i--)
        {
            if(nums[i] + i >= index)
                index = i;
        }
        
        if(index==0)
            return true;
        else
            return false;
    }
};