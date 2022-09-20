// class Solution {
// public:
//     int maximumProduct(vector<int>& nums) {
//         //sort to get ascending order so that largest numbers are at the end and smallest or negatives will be at start
//         //Ex - {2,-3,3,-1,4} => {-3,-1,2,3,4}
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
        
//         // combination1 will be product of largest 3 numbers
//         int combination1 = nums[n-1]*nums[n-2]*nums[n-3];
//         // combination2 => lets take this test case as demo
//         // prod of 2 negatives will make it positive and then multiplying that with the largest element can give the                largest product possible
//         // Ex -> {-10,-9,1,2,3}
//         int combination2 = nums[0]*nums[1]*nums[n-1];
        
//         // now check which combination is maximum
//         return max(combination1,combination2);
//     }
// };

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        //optimized  is just find min1,min2 and max1,max,2,max3 by comparing each elements.
        int min1=INT_MAX,min2=INT_MAX;
        int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN;
        
        int n = nums.size();
        for(int i=0;i<n;i++){
            //finding min elements.
            if(nums[i] <= min1){
                min2 = min1;
                min1 = nums[i];
            }
            else if(nums[i] <= min2){
                min2 = nums[i];
            }
            //finding max elements.
            if(nums[i] >= max1){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i] >= max2){
                max3 = max2;
                max2 = nums[i];
            }
            else if(nums[i] >= max3){
                max3 = nums[i];
            }
            
        }
        return (max(min1*min2*max1,max1*max2*max3));
    }
};