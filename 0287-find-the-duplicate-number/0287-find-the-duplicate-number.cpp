// Brute Force with sorting => Time Complexity:O(Nlogn + N)
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         int answer;
        
//         sort(nums.begin(),nums.end());
        
//         for(int i=0;i<n-1;i++)
//         {
//             if(nums[i] == nums[i+1])
//             {
//                 answer =  nums[i]; 
//                 break;
//             }
//         }
        
//         return answer;
//     }
// };

// Optimized Approach => Time Complexity:O(N)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int answer;
        
        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto i : mp)
        {
            if(i.second > 1)
            {
                answer = i.first;
                break;
            }
        }
        
        return answer;
    }
};

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int slow = nums[0];
//         int fast = nums[0];
//         while (true)
//         {
//             slow=nums[slow];
//             fast=nums[nums[fast]];
//             if(slow==fast)
//             {
//                 break;
//             }
//         }
        
//         fast = nums[0];
//         while(slow!=fast)
//         {
//             slow = nums[slow];
//             fast = nums[fast];
//         }
        
//         return slow;
//     }
// };
