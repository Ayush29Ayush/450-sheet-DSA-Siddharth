//! Approach1 -> Linear Search 
// TC -> O(n) and SC -> O(1)
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
        
//         for(int i=0; i<nums.size(); i++)
//         {
//             if(nums[i]==target)
//                 return i;
//         }
//         return -1;
//     }
// };

//! Approach2 -> Binary Search
// refer -> https://www.youtube.com/watch?v=r3pMQ8-Ad5s
class Solution {
public:
    int search(vector < int > & nums, int target) {
      int low = 0, high = nums.size() - 1; 

      while (low <= high) 
      {
          int mid = (low + high)/2;
          
          if (nums[mid] == target)
              return mid;
          
          if (nums[low] <= nums[mid]) 
          {
              if (nums[low] <= target && nums[mid] >= target)
                high = mid - 1; 
              else
                low = mid + 1; 
          }
          else 
          { 
              if (nums[mid] <= target && target <= nums[high])
                low = mid + 1;
              else
                high = mid - 1;
          }
      }
      return -1; 
    }

};