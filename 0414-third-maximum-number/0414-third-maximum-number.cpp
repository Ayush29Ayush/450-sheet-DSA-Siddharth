// Approach1: Use set and store all unique elements. Then vector<int> v(s.begin(), s.end()) se set to vector karke sort karo vector ko and return n-3 if size>=3 else n-1 return karna

// Approach2: Use sort function and count to check 3rd largest
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        if(n<3){
            return nums[n-1];
        }
        
        int count = 1;
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]!=nums[i])
                count++;
            if(count==3)
                return nums[i];
        }
        
        return nums[n-1];
    }
};