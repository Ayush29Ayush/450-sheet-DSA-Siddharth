//!Brute Force Approach:
// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int> &nums){
//         int n = nums.size();
//         vector<int> ans(n);
//         for (int i = 0; i < n; i++){
//             ans[i] = -1;
//             for (int j = 1; j < n; j++){
//                 if (nums[i] < nums[(i + j) % n]){
//                     ans[i]= nums[(i + j) % n];
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }

// };

//! Optimised solution using stack
//! TC - O(n)
//! refer this -> https://www.youtube.com/watch?v=dvMdn0ARtf0
//! refer striver video too -> https://www.youtube.com/watch?v=Du881K7Jtk8&t=74s
class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums){
    int n = nums.size();
    stack<int> s;
    vector<int> ans(n);
        
    for (int i = n-1; i >= 0; i--){
        while (!s.empty() && s.top() <= nums[i])
            s.pop();

        ans[i] = s.empty() ? -1 : s.top();
        
        s.push(nums[i]);
    }
        
    for (int i = n-1; i >= 0; i--){
        if(ans[i] == -1){
            while (!s.empty() && s.top() <= nums[i])
            s.pop();

            ans[i] = s.empty() ? -1 : s.top();
        }
        s.push(nums[i]);
    }
    
    return ans;
}

};