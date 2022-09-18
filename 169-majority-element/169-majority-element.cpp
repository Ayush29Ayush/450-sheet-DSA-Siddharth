/*Explanation:
1. Basic idea is that we will sort the array
2. The element which is present more than size/2 time must appear at the mid of the vector.
3. Return the middle element.
Ex-> {6,6,2,3,6} here size = n = 5 so maximum element has to appear more that n/2 times so more that 2 times. 
*/
// using sorting -> O(NlogN)
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(),nums.end()); // sort the vector
//         return nums[nums.size()/2];   // middle element will be the most frequent Element
//     }
// };


// using hashmap -> O(N)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(auto element : nums)
            mp[element]++;
        
        int max = INT_MIN;
        int ans = 0;
        
        for(auto element : mp)
        {
            if(element.second>max)
            {
                max = element.second;
                ans = element.first;
            }    
        }
        return ans;
    }
};