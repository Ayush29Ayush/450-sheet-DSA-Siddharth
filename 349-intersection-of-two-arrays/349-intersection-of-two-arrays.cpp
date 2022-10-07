class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // we insert values in a set so that duplicates are taken care of
        unordered_set<int> s1,s2;
        vector<int> vec;
        
        // for(int i=0; i<nums1.size(); i++)
        // {
        //     s1.insert(nums1[i]);
        // }
        // for(int i=0; i<nums2.size(); i++)
        // {
        //     s2.insert(nums2[i]);
        // }
        // iterator approach to insert elements
        for(auto element : nums1)
            s1.insert(element);
        for(auto element : nums2)
            s2.insert(element);
        
        // if any element which is present in s1 in found in s2, that means its an intersection so push it to vec
        for(auto x : s1)
        {
            if(s2.find(x)!=s2.end())
            {
                vec.push_back(x);
            }
        }
        
        return vec;
    }
};