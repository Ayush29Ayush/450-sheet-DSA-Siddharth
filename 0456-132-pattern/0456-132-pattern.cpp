// //Approach-1
// //T.C : O(n^3) - T.L.E : [94 / 103 test cases passed.]
// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//         int n = nums.size();
//         for(int i = 0; i<n; i++) {
            
//             for(int j = i+1; j<n; j++) {
                
//                 if(nums[j] > nums[i]) {
                    
//                     for(int k = j+1; k<n; k++) {
//                         if(nums[i] < nums[k] && nums[k] < nums[j] )
//                             return true;
//                     }
                    
//                 }
//             }
//         }
//         return false;
//     }
// };

// //Approach-2
// //T.C : O(n^2) - T.L.E : [101 / 103 test cases passed.]
// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//         int min_i = INT_MAX;
//         int n = nums.size();
//         for(int j = 0; j<n-1; j++) {
//             min_i = min(min_i, nums[j]);
//             for(int k = j+1; k<n; k++) {
//                 if(min_i < nums[k] && nums[k] < nums[j])
//                     return true;
//             }
//         }
//         return false;
//     }
// };

//Approach-3 --> Using Monotonic stack
//T.C : O(n) - We don't visit any element more than once
/*
    We are only storing one item in the stack, which is our ideal candidate for num2 (number that needs to be the largest). 
    If we find a number that is bigger than what we thought was our ideal candidate for num2; we pop out our stack 
    and store the value in num3 (mid value number), then we store the new ideal candidate for num2 in the stack. 
    On the next ith iteration, if nums[i] is actually less than s3, then we are done!
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // i  ,  j  ,  k
        //num1, num2, num3
        //num1 < num3 < num2    means nums2 sabse bada hona chahiye and nums1 sabse chota among these 3 numbers
        int n = nums.size();
        int nums3 = INT_MIN; // hamesha jo chahiye uska opposite se initialize karo
        
        // we will be using the concept of monotonic stack here so data will be stored either in increasing or decreasing order.
        stack<int> st;
        // we will traverse from n-1 to 0 so that we do not have to worry about i<j<k wala condition
        
        for(int i=n-1; i>=0; i--)
        {
            // base case
            if(nums[i]<nums3)
                return true;
            
            while(!st.empty() && st.top() < nums[i])
            {
                // here according to the logic nums2 will be largest i.e nums[i] and second largest will be nums3 i.e st.top() which is st.top() < nums[i]
                nums3 = st.top();
                st.pop();
            }
            
            st.push(nums[i]);
        }
        
        return false;
    }
};