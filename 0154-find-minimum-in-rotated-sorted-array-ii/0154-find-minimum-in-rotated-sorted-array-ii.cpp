//! Approach1 -> Use STL
// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         return *min_element(nums.begin(), nums.end());
//     }
// };

//! Approach2 -> Use Binary Search
class Solution {
public:
	int findMin(vector<int>& nums) {
		int l=0,r=nums.size()-1;
		while(l<r){
			int mid=(l+r)/2;
			//additional condition to handle conflict when all three values are equal
			if(nums[l]==nums[mid] && nums[mid]==nums[r]){
				l++;
				r--;
			}
			else if(nums[mid]>nums[r])
				l=mid+1;
			else 
				r=mid;
		}
		return nums[l];
	}
};