//! Approach1 => Brute Force
// class Solution {
// public:
//     int findMaxLength(vector<int>& nums) {
//         int count = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             int zeros = 0, ones = 0;
//             for (int j = i; j < nums.size(); j++) {
//                 if (nums[j] == 0) {
//                     zeros++;
//                 } else {
//                     ones++;
//                 }
//                 if (zeros == ones) {
//                     count = max(count, j - i + 1);
//                 }
//             }
//         }
//         return count;
//     }
// };


//! refer this video => https://www.youtube.com/watch?v=O6B7AmTqxlQ
//! Approach2 => Change 0 to -1 and apply PREFIX SUM concept
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp; 
        
        
        for(int i = 0; i < nums.size(); i++) 
            if(nums[i] == 0) 
                nums[i] = -1;
        
        int sum=0,maxLen=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            //1. agar sum=0 mil gaya means ek subarray mil gaya, so store its length i.e i+1
            if(sum == 0){
                maxLen = max(maxLen, i+1); // +1 because 0 bassed indexing
            }
            //3. agar koi sum pehle se map mein hai means abhi ka occurance - pehle ka occurance = subarray with 0 mil gaya. Bass uska size dekhlo
            if(mp.find(sum)!=mp.end()){ //sum is in map
                maxLen=max(maxLen,i-mp[sum]);
            }
            //2. jo bhi sum aaya usko map mein store karlo where key:value => sum:index
            else{
                mp[sum]=i;
            }
        }
        return maxLen;
    }
};