//! Approach1 -> using SORT T.C=>O(n+mlog(n+m)) S.C=>O(n+m)
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans;
        
//         for(auto element : nums1) ans.push_back(element);
//         for(auto element : nums2) ans.push_back(element);
        
//         sort(ans.begin(), ans.end());
        
//         int n = ans.size();
        
//         if(n%2==0)
//             return (ans[n/2]+ans[n/2-1])/2.0;
//         else
//             return ans[n/2];
//     }
// };



// Optimized Using: Two Pointer with Extra Space => MERGE SORT 
  // Time Complexity: O(m+n)
  // Space Complexity: O(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // Create a single sorted by merging two sorted arrays
        int n1=nums1.size();
        int n2=nums2.size();
        int i=0;
        int j=0;
        int lastindex=-1;
             
        // Initialize a new array
           vector<int>v(n1+n2,0);
        
        while(i<n1&&j<n2)
        {
            if(nums1[i]<=nums2[j])
                v[++lastindex]=nums1[i++];
            else
                v[++lastindex]=nums2[j++];
        }
        
        while(i<n1)
            v[++lastindex]=nums1[i++];
        while(j<n2)
            v[++lastindex]=nums2[j++];
        
    // Return the result
        int n=n1+n2;
        return n%2?v[n/2]:(v[n/2]+v[n/2-1])/2.0;
        
    }
};