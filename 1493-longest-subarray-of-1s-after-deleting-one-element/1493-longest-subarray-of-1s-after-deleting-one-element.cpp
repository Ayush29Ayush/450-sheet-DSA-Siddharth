// Youtube Video for reference : https://www.youtube.com/watch?v=SQ8tY9nxeZU
// Similar Problem             : Leetcode - 1004, 487, 485
// COmpany Tags                : Google, Meta 

// Approach1 :- Simple Brute Force  T.C : O(n^2)
// class Solution {
// public:
//     int n;
    
//     // step3
//     int findMax(vector<int>& nums, int skip_idx)
//     {
//         int currLength = 0;
//         int maxLength = 0;
        
//         for(int i=0; i<n; i++)
//         {
//             if(i==skip_idx)
//                 continue;
            
//             if(nums[i]==1)
//             {
//                 currLength++;
//                 maxLength = max(maxLength,currLength);
//             }
//             else
//             {
//                 currLength = 0;
//             }
//         }
//         // step4
//         return maxLength;
//     }
    
//     int longestSubarray(vector<int>& nums) {
//         n = nums.size();
//         int result = 0;
        
//         // step5     nums = [1,1,1] output = 2 i.e (n-1)
//         int countZero = 0;        
        
//         // step1
//         for(int i=0; i<n; i++)
//         {
//             // step2
//             if(nums[i]==0)
//             {
//                 countZero++; // step6
//                 result = max(result, findMax(nums,i));
//             }
//         }
        
//         // step7
//         if(countZero==0)
//             return n-1;
        
//         return result;
//     }
// };

//! Approach2 :- Using Sliding Window  T.C : O(n)
// Window ka size => (j-i+1) but we have to remove one zero so (j-i+1)-1 => (j-i)
// Ek window mein ek hi zero delete kar sakte ho so we allow one zero in the window, but jesse hi more than one zero aa jaye window mein, we have to act on it.
// [1,1,0,0,1,1,1,0,1] mein last ka windows mein [1,1,1,0,1] allowed tha so that ek zero nikalne ke baad, we get [1,1,1,1] which is the longest subarray with 1.
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0;
        int countZero = 0;
        int windowwithmaxonezero = 0;
        
        for(int j=0; j<nums.size(); j++)
        {
            // step2
            if(nums[j]==0)
                countZero++;
            
            // step3
            // Trigger point for sliding window, window chota karo ab. Agar 0 mila shrink karte time toh countzero-- bhi kar dena varna i++ karke shrink toh karna hi hai
            while(countZero>1)
            {
                if(nums[i]==0)
                    countZero--;
                i++; // until window mein bass ek zero bach jaye
            }
            
            // step1
            windowwithmaxonezero = max(windowwithmaxonezero, (j-i));
        }
        
        // step4
        return windowwithmaxonezero;
    }
};