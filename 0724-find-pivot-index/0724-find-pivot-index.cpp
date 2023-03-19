// https://www.youtube.com/watch?v=AH-YhFNJoas
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            totalSum += nums[i];
        }
        
        int leftSum = 0; // left se right dir pe jayega
        int rightSum = totalSum; // right se left dir pe jayega
        
        // ab traverse karte time prefix_sum algo apply karo
        for(int i=0; i<nums.size(); i++)
        {
            // pehle rightSum ko adjust karke compare karlo
            // jis index pe aa gaye uska element minus kardo so that total se minus ho jaye
            rightSum = rightSum - nums[i];
            
            if(leftSum == rightSum)
            {
                return i;
            }
            
            // ab comparision ka kaam ho gaya so leftSum mein apna contribution dedo
            // i.e ab next index pe jaane se pehle leftSum mein current index ka element add kardo
            leftSum = leftSum + nums[i];
        }
        
        // pivot nahi mila toh return -1
        return -1;
    }
};