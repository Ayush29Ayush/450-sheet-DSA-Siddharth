// take out n = size/3
// create a map and store the key value pair of element and its freq
// now traverse and when element's freq is more than n, push it to the vector

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size()/3;
        vector<int> ans;
        
        unordered_map<int, int> mp;
        
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto i: mp)
        {
            if(i.second>n)
                ans.push_back(i.first);
        }
        
        return ans;
    }
}; 