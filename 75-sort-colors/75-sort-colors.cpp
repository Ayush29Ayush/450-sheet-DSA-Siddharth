// https://leetcode.com/problems/sort-colors/discuss/2171105/C%2B%2B-solution-Count-0's-1's-2's-0ms-Faster-than-100-TC-greater-O(n)

// Keeping a count of 0's 1's and 2's and updating the original array
//Time complexity - O(2N)
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int count0 = 0, count1 = 0, count2 = 0;
        
//         for(int i = 0;i<nums.size();i++)
//         {
//             if(nums[i]==0)
//                 count0++;
//             if(nums[i]==1)
//                 count1++;
//             if(nums[i]==2)
//                 count2++;
//         }
        
//         int i = 0;
//         while(count0)
//         {
//             nums[i] = 0;
//             i++;
//             count0--;
//         }
//         while(count1)
//         {
//             nums[i] = 1;
//             i++;
//             count1--;
//         }
//         while(count2)
//         {
//             nums[i] = 2;
//             i++;
//             count2--;
//         }
//     }
// };

class Solution {
	public:
		void sortColors(vector<int>& nums) {
			int start=0;          
			int end=nums.size()-1;    
			for(int i=0;i<=end;i++){
				if(nums[i]==0){   
                    // this will put all the 0's in starting positions
					swap(nums[i],nums[start++]);  
				}
				else if(nums[i]==2){
                    // this will put all the 2's in the ending positions
					swap(nums[i--],nums[end--]);  
				}
			}
		}
	};