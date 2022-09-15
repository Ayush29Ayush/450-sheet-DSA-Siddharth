// class Solution {
// public:
//         ! Brute Force
//     //! TC - > O(N*M)
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans;
        
//         for(int i = 0; i < nums1.size(); i++){
//             for(int j = 0; j < nums2.size(); j++){
//                 if(nums1[i]==nums2[j])
//                     {
//                     int next = -1;
//                         for(int k = j; k<nums2.size(); k++)
//                         {
//                             if(nums2[k] > nums2[j])
//                             {
//                                 next = nums2[k];
//                                 break;
//                             }
//                         }
//                         ans.push_back(next);
//                     }
//                 }
//             }
//         return ans;
//     }
// };

//! Optimal Solution: Using Stack and Map
//! TC -> O(N) and SC -> O(N)
//! refer -> https://www.youtube.com/watch?v=ELjbzOQ-liI
//! do dry run for better understanding

//! refer this too -> https://youtu.be/Du881K7Jtk8?t=447
class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>m;

        for(int i=nums2.size()-1; i>=0; i--)
        {
            while(!st.empty() && st.top() <= nums2[i])
                st.pop();

            if(st.empty())
                m[nums2[i]] = -1;

            else
                m[nums2[i]] = st.top();

            st.push(nums2[i]);
        }

        for(int i=0; i<nums1.size(); i++)
            nums1[i] = m[nums1[i]];

        return nums1;
    }
};