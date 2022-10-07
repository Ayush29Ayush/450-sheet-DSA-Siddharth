class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
	    //unordered_set is implemented using a hash table where keys are hashed into indices of a hash table
	    // all operations take O(1) on average
        
        
        unordered_set<int> n1;
        unordered_set<int> n2;
        // insert all the elements in the set
        for(int i=0;i<nums1.size();i++)
            n1.insert(nums1[i]);
        // insert all the elements in the set
        for(int i=0;i<nums2.size();i++)
            n2.insert(nums2[i]);
        
        // 1D vector to store non matching elements
        vector<int> ans1;
        // 2D array to store the 1D vectors
		vector<vector<int>> ans;
        
        // finding elements in n1 which are not in n2 
        for(int x:n1)
        {
            if(n2.find(x)==n2.end())
                ans1.push_back(x);
        }
        
		ans.push_back(ans1);
		ans1.clear();
        // finding elements in n2 which are not in n1 
        for(int x:n2)
        {
            if(n1.find(x)==n1.end())
                ans1.push_back(x);
        }
        // push the final ans
        ans.push_back(ans1);
        return ans;
    }
};