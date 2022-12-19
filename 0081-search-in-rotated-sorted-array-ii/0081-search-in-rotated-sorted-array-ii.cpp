// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/discuss/1890199/C%2B%2B-oror-Algorithm-oror-Binary-Search
//! Approach1 -> Linear Search       Time Complexity : O(n)
// class Solution {
// public:
//     bool search(vector<int>& nums, int target) {
//         for(int i = 0; i < nums.size(); i++)
//             if(nums[i] == target) return true;
//         return false;
//     }
// };

//! Approach2 -> Binary Search     Time Complexity : O(logn)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r)
        {
            int mid = l + (r-l) / 2;
            if (nums[mid] == target)
                return true;
			// with duplicates we can have this contdition, just update left & right
            if((nums[l] == nums[mid]) && (nums[r] == nums[mid]))
            {
                l++;
                r--;
            }
			// first half
			// first half is in order
            else if(nums[l] <= nums[mid])
            {
				// target is in first  half
                if((nums[l] <= target) && (nums[mid] > target))
                    r = mid - 1;
                else
                    l = mid + 1;
            }
			// second half
			// second half is order
			// target is in second half
            else
            {
                if((nums[mid] < target) && (nums[r]>= target))
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
};