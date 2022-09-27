// subarrays are continous and maintain order
// [2,1,4,3] can form [2], [2,1], [2,1,4], [2,1,4,3], [1], [1,4], [1,4,3], [4], [4,3], [3]
// we use 2 pointer here
// traverse and check if nums[i] with left and right pointer
//! Do dry run for better understanding
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
       //initialize a counter & two pointers for the boundaries
    int counter=0, start=-1, end=-1;
    
    for(int i=0;i<nums.size();i++){
        
        //move the end pointer to the position of the next invalid number
        if(nums[i]>right)
            end=i;
        //move the start pointer to the position of the first valid number
        if(nums[i]>=left)
            start=i;
        
        //subtract the two ones to get the distance, number of valid values, between the two pointers & add it to the counter
        counter+=start-end;
    }
    
    //return the final counter value
    return counter;  
    }
};